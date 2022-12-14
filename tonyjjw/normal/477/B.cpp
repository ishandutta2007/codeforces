//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 10000

using namespace std;

int N,K;
int ans[MN][4];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		ans[i][0]=(6*i+1)*K;
		ans[i][1]=(6*i+2)*K;
		ans[i][2]=(6*i+3)*K;
		ans[i][3]=(6*i+5)*K;
	}
	printf("%d\n",ans[N-1][3]);
	for(i=0;i<N;i++){
		for(j=0;j<4;j++)printf("%d ",ans[i][j]);
		puts("");
	}
	return 0;
}

//*/