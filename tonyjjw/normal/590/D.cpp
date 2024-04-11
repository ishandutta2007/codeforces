//*

#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long ll;

const int MN = 150;

int N,K,S;
int A[MN];
int D[2][MN+1][MN*(MN-1)/2 + 1];

const int INF = 1e9;

int main(){
	scanf("%d%d%d",&N,&K,&S);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int LIM=N*(N-1)/2;
	for(int j=0;j<=N;j++)for(int k=0;k<=LIM;k++)D[0][j][k]=INF;
	D[0][0][0]=0;
	D[0][1][0]=A[0];

	for(int i=1;i<N;i++)for(int j=0;j<=N;j++)for(int k=0;k<=LIM;k++){
		int t=i&1;
		D[t][j][k]=D[t^1][j][k];
		if(j-1>=0 && k-i>=0 && D[t][j][k]>D[t^1][j-1][k-i]+A[i]){
			D[t][j][k]=D[t^1][j-1][k-i]+A[i];
		}
	}
	int t=(N-1)&1;
	int ans=INF;
	for(int k=0;k<=LIM && k<=S+K*(K-1)/2;k++){
		if(ans>D[t][K][k])ans=D[t][K][k];
	}
	printf("%d\n",ans);
	return 0;
}

//*/