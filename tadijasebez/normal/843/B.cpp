#include <stdio.h>
#include <queue> 
#include <ctime>
#include <stdlib.h>
using namespace std; 
int main() 
{
srand(time(0));
 	int n,x,first,i;
 	pair<int,int> TopBest,BotBest,Cur;
 	bool okTop=false,okBot=false;
 	scanf("%i %i %i",&n,&first,&x);
 	for(i=0;i<1000;i++)
 	{
int u=(rand()^rand()+rand())%n+1;
 		printf("? %i\n",u);
 		fflush(stdout);
 	scanf("%i%i",&Cur.first,&Cur.second); 		if(Cur.first<x) 		{ 			if(!okBot || BotBest.first<Cur.first) BotBest=Cur; 			okBot=true; 		} 		else 		{ 			if(!okTop || TopBest.first>Cur.first) TopBest=Cur; 			okTop=true; 		} 	} 	if(!okBot) 	{ 		printf("? %i\n",first); 		fflush(stdout); 		scanf("%i %i",&Cur.first,&Cur.second); 		while(Cur.first<x && Cur.second>-1) 		{ 			printf("? %i\n",Cur.second); 			fflush(stdout); 			scanf("%i %i",&Cur.first,&Cur.second); 		} 		if(Cur.first<x) printf("! -1\n"); 		else printf("! %i\n",Cur.first); 		return 0; 	}
if(BotBest.second==-1)
{
 printf("! -1");
 return 0;
}
 	printf("? %i\n",BotBest.second); 	fflush(stdout); 	scanf("%i %i",&Cur.first,&Cur.second); 	while(Cur.first<x && Cur.second>-1) 	{ 		printf("? %i\n",Cur.second); 		fflush(stdout);
 		scanf("%i %i",&Cur.first,&Cur.second);
 	} 	if(Cur.first<x) printf("! -1\n"); 	
else printf("! %i\n",Cur.first);
 	return 0;
}