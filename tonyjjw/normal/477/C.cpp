//*

#include<stdio.h>
#include<algorithm>
#include<string.h>
#pragma warning(disable:4996)
#define MN 2000
#define MM 500
#define INF 9999999

using namespace std;

char s1[MN+1],s2[MM+1];
int C[MN],P[MN];
int D[MN+1][MN+1];
int N,M;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%s%s",s1,s2);
	N=strlen(s1),M=strlen(s2);
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			while(i+j+C[i]<N && s1[i+j+C[i]]!=s2[j])C[i]++;
			if(i+j+C[i]==N)break;
			if(j==M-1)P[i]=i+j+C[i]+1;
		}
		if(j<M)C[i]=-1,P[i]=-1;
	}
	for(i=0;i<=N;i++){
		for(j=0;j<=N;j++)if(N-i<j)D[i][j]=-INF;
	}
	
	for(i=N-1;i>=0;i--){
		if(P[i]==-1)continue;
		else{
			if(C[i]==0)D[i][0]=D[P[i]][0]+1;
			else	D[i][0]=D[i+1][0];
		}
		for(j=1;j<=N;j++){
			if(N-i<j){
				continue;
			}
			D[i][j]=D[i+1][j];
			if(D[i][j]<D[i+1][j-1])D[i][j]=D[i+1][j-1];
			if(P[i]==-1)continue;
			if(j-C[i]>=0 && D[i][j]<D[P[i]][j-C[i]]+1)D[i][j]=D[P[i]][j-C[i]]+1;
		}
	}
	for(i=0;i<=N;i++){
		printf("%d ",D[0][i]);
	}
	return 0;
}

//*/