//*

#include<stdio.h>
#include<string.h>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 100000

int N;
char map[MN][2][51];
char *name[MN][2],*max="A";

bool cmp(char *A,char *B){
	return strcmp(A,B)<0;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,k;
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%s%s",map[i][0],map[i][1]),name[i][0]=map[i][0],name[i][1]=map[i][1];
	for(i=0;i<N;i++){
		scanf("%d",&k),--k;
		char *a=name[k][0],*b=name[k][1];
		if(!cmp(a,b))std::swap(a,b);
		if(!cmp(max,a)){
			if(!cmp(max,b)){
				puts("NO");
				return 0;
			}
			max=b;
		}
		else{
			max=a;
		}
	}
	puts("YES");
	return 0;
}

//*/