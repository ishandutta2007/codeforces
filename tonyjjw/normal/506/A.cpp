//*
#include<stdio.h>
#include<algorithm>
#define MN 30000
#define MD 800
#define ZERO 400
#pragma warning(disable:4996)

using namespace std;

int N,D;
int cnt[MN+1];
int DD[MN+1][MD];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j,ans=0;
	scanf("%d%d",&N,&D);
	for(i=0;i<N;i++){
		scanf("%d",&j);
		cnt[j]++;
	}
	for(i=0;i<=MN;i++)for(j=0;j<MD;j++)DD[i][j]=-1e9;
	DD[D][ZERO]=cnt[D];
	ans=cnt[D];
	for(i=D+1;i<=MN;i++){
		for(j=-299;j<=299;j++){
			if(i-(D+j)<0)continue;
			if(D+j<=0)continue;
			DD[i][ZERO+j]=max(DD[i-(D+j)][ZERO+j],max(DD[i-(D+j)][ZERO+(j-1)],DD[i-(D+j)][ZERO+(j+1)]))+cnt[i];
			if(ans<DD[i][ZERO+j])ans=DD[i][ZERO+j];
		}
	}
	printf("%d",ans);
	return 0;
}
//*/