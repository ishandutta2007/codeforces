//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 30
#define MK 200
using namespace std;

int N,K;
int A[MN];
double D[MN][MN][MK+1];

int f(int l,int r,int n){
	if(l<=n && n<=r){
		return l+r-n;
	}
	return n;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<i;j++)D[i][j][0]=1;
		for(int j=i+1;j<N;j++)D[i][j][0]=0;
	}
	int num=(N+1)*N/2;
	for(int k=1;k<=K;k++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(i==j)continue;
				for(int l=0;l<N;l++){
					for(int r=l;r<N;r++){
						int ni=f(l,r,i);
						int nj=f(l,r,j);
						D[i][j][k]+=D[ni][nj][k-1]/num;
					}
				}
			}
		}
	}
	double ans=0;
	for(int i=0;i<N;i++){
		for(int j=i+1;j<N;j++){
			if(A[i]<A[j])ans+=D[i][j][K];
			else  ans+=D[j][i][K];
		}
	}
	printf("%.12lf",ans);
	return 0;
}
//*/