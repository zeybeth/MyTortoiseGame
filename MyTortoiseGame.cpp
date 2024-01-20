#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
	int n;
	srand(time(NULL));
	printf("\tWelcome to the Tortoise Game.");
	printf("\nPlease specify the size of the board: ");
	scanf("%d",&n);
	
	char arr[n][n];//my board
	int times=0;
	int mulberry=ceil(0.15*n*n);
	char action, place, M, N, S, E, W;
	int pit=ceil(0.05*n*n);
	int energy=20;
	int i,j;//for loop
	int at;//tortoise x
	int bt ;//tortoise y
	int a,b ;//coordinates

	for(i=0;i<n;i++){ //board draft
		for(j=0;j<n;j++){
			arr[i][j]='_';
		}
	}
	//place of tortoise
	at=rand()%n;
	bt=rand()%n;
	arr[at][bt]='@';
	a=at;
	b=bt;
	
	for(i=0;i<mulberry;i++){ //putting mulberry
		a=rand()%n;
		b=rand()%n;
   		if(arr[a][b]=='@'){
       		i--;
		}
   		 else
			arr[a][b]='*';
		}
	
	for(i=0;i<pit;i++){ //putting pit
		a=rand()%n;
		b=rand()%n;
   		if((arr[a][b]=='@')||(arr[a][b]=='*')){
      		i--;
		}
    	else
			arr[a][b]='O';
	}
	
	printf("Time = %d Energy level: %d\n",times,energy);
	for(i=0;i<n;i++){ //printing the board
		for(j=0;j<n;j++){
			printf("%c ",arr[i][j]);
		}
		printf("\n");
	}
	times = 1, energy=19;
	while(energy>0 && mulberry>0 ){ //game continuity
		printf("\nPlease enter an action:");
		scanf(" %c %c",&action, &place);
		printf("Time = %d Energy level: %d\n",times,energy);
		if(action=='M'){  //hareket durumlarý
			if((place=='N') && (arr[at-1][bt]!='*') && (at!=0) && (arr[at-1][bt]!='O') ){ //move north
				arr[at][bt]='_';
				at-=1;
				arr[at][bt]='@';
				energy-=1;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='N') && (at!=0) && (arr[at-1][bt]=='O')){ //fall north
				arr[at][bt]= '_';
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
				printf("YOU LOST :-( \nTHE GAME IS OVER!");
				return 0;
			}	
				
			else if((place=='S') && (arr[at+1][bt]!='*') && (arr[at+1][bt]!='O')){ // move south
				arr[at][bt]='_';
				at+=1;
				arr[at][bt]='@';
				energy-=1;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
					printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='S') && (arr[at+1][bt]=='O')){ //fall south
				arr[at][bt]='_';
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
				printf("YOU LOST :-( \nTHE GAME IS OVER!");
				return 0;
			}
			else if((place=='E') && (arr[at][bt+1]!='*') && (arr[at][bt+1]!='O')){ //move east
				arr[at][bt]='_';
				bt+=1;
				arr[at][bt]='@';
				energy-=1;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
					printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='E') && (arr[at][bt+1]=='O')){ //fall east
				arr[at][bt]='_';
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
				printf("YOU LOST :-( \nTHE GAME IS OVER!");
				return 0;
			}
			else if((place=='W') && (arr[at][bt-1]!='*') && (bt!=0) && (arr[at][bt-1]!='O')){ //move west
				arr[at][bt]='_';
				bt-=1;
				arr[at][bt]='@';
				energy-=1;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='W') && (bt!=0) && (arr[at][bt-1]=='O')){ //fall west
				arr[at][bt]='_';
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
				printf("YOU LOST :-( \nTHE GAME IS OVER!");
				return 0;
			}
			else{ //otherwise
				arr[at][bt]='@';
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
		}
		else if(action=='E'){ //eat action
			if((place=='N') && (arr[at-1][bt]=='*') && (at!=0)){ //eat north
				arr[at-1][bt]='_';
				arr[at][bt]='@';
				mulberry-=1;
				energy+=10;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='S') && (arr[at+1][bt]=='*')){ //eat south
				arr[at+1][bt]='_';
				arr[at][bt]='@';
				mulberry-=1;
				energy+=10;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='E') && (arr[at][bt+1]=='*')){ //eat east
				arr[at][bt+1]='_';
				arr[at][bt]='@';
				mulberry-=1;
				energy+=10;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
			else if((place=='W') && (arr[at][bt-1]=='*') && (bt!=0)){ //eat west
				arr[at][bt-1]='_';
				arr[at][bt]='@';
				mulberry-=1;
				energy+=10;
				times+=1;
				for(i=0;i<n;i++){
					for(j=0;j<n;j++){
						printf("%c ",arr[i][j]);
					}
					printf("\n");
				}
			}
		}
			
	}
	if(energy<=0) //game over
		printf("YOU LOST :-( \nTHE GAME IS OVER!");
	else if(mulberry==0)
		printf("CONGRAGULATIONS, YOU WON :-)");
	
	
	return 0;
}

