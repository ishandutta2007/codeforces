//*

#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

char str[6][100]={"+------------------------+","|#.#.#.#.#.#.#.#.#.#.#.|D|)","|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|","|#.#.#.#.#.#.#.#.#.#.#.|.|)","+------------------------+"};

int N;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int i,j;
	if(N<=4){
		for(i=0;i<N;i++){
			str[i+1][1]='O';
		}
		for(i=0;i<6;i++){
			if(i<5)printf("%s\n",str[i]);
			else
			{
				printf("%s",str[i]);
			}
		}
		return 0;
	}
	for(i=0;i<4;i++)str[i+1][1]='O';
	N-=4;
	for(j=3;;j+=2){
		if(N<=3){
			if(N==3){
				str[1][j]=str[2][j]=str[4][j]='O';
				break;
			}
			for(i=0;i<N;i++)str[1+i][j]='O';
			break;
		}
		str[1][j]=str[2][j]=str[4][j]='O';
		N-=3;
	}
	for(i=0;i<6;i++){
		if(i<5)printf("%s\n",str[i]);
		else
		{
			printf("%s",str[i]);
		}
	}
	return 0;
}

//*/