//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 400
#define INF 1e9
using namespace std;

int N,K;
int A[MN],S[MN];
int D[MN][MN][51];

inline int sum(int l,int r){
	if(!l)return S[r];
	return S[r]-S[l-1];
}

inline int mabs(int a){
	if(a<0)return -a;
	return a;
}

int pos[MN][MN][2];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=1;k<=K;k++)D[i][j][k]=-INF;
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		S[i]=A[i];
	}
	for(int i=1;i<N;i++){
		S[i]+=S[i-1];
	}
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			int v=-INF;
			for(int k=i;k<j;k++){
				if(v<sum(i,k)){
					v=sum(i,k);
					pos[i][j][0]=k;
				}
			}
			v=INF;
			for(int k=i;k<j;k++){
				if(v>sum(i,k)){
					v=sum(i,k);
					pos[i][j][1]=k;
				}
			}
		}
	}
	for(int i=0;i<N;i++)for(int j=i;j<N;j++)D[i][j][1]=0;
	int v;
	for(int k=2;k<=K;k++){
		for(int j=0;j<N;j++){
			for(int p=0;p<j;p++){
				int i=pos[p][j][0]+1;
				v=D[p][i-1][k-1]+mabs(sum(i,j)-sum(p,i-1));
				if(D[i][j][k]<v){
					D[i][j][k]=v;
				}
				i=pos[p][j][1]+1;
				v=D[p][i-1][k-1]+mabs(sum(i,j)-sum(p,i-1));
				if(D[i][j][k]<v){
					D[i][j][k]=v;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<N;i++)for(int j=i;j<N;j++)if(ans<D[i][j][K])ans=D[i][j][K];
	printf("%d",ans);
	return 0;
}
//*/