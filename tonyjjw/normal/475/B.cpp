//*

#include<stdio.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define MN 20

using namespace std;

int N,M;
int V[MN][MN];
char s1[MN+1],s2[MN+1];

void dfs(int i,int j){
	int di,dj;
	V[i][j]=1;
	di=i,dj=j;
	if(s1[i]=='<')dj--;
	if(s1[i]=='>')dj++;
	if(dj>=0 && dj<M && !V[di][dj])dfs(di,dj);

	di=i,dj=j;
	if(s2[j]=='v')di++;
	if(s2[j]=='^')di--;
	if(di>=0 && di<N && !V[di][dj])dfs(di,dj);
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	scanf("%s%s",s1,s2);
	int i,j,k,l,ans=1;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			for(k=0;k<N;k++)for(l=0;l<M;l++)V[k][l]=0;
			dfs(i,j);
			for(k=0;k<N;k++)for(l=0;l<M;l++)if(!V[k][l])ans=0;
		}
	}
	if(ans){
		printf("YES");
	}
	else{
		printf("NO");
	}
	return 0;
}

//*/