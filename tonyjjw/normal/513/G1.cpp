//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 6
using namespace std;

int N,K;
int A[MN];

void inverse(int l,int r){
	while(l<r){
		swap(A[l],A[r]);
		l++,r--;
	}
}

int total;

void dfs(int t){
	if(t==K){
		for(int i=0;i<N;i++){
			for(int j=i;j<N;j++){
				if(A[i]>A[j])total++;
			}
		}
		return;
	}
	for(int i=0;i<N;i++){
		for(int j=i;j<N;j++){
			inverse(i,j);
			dfs(t+1);
			inverse(i,j);
		}
	}
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&K);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	dfs(0);
	double v=1;
	for(int i=1;i<=K;i++){
		v*=(N+1)*N/2;
	}
	printf("%.12lf",(double)total/v);
	return 0;
}
//*/