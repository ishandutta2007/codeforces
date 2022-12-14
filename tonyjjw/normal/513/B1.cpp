//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define push_back pb
#define emplace_back eb
#define make_tuple mt
#define MN 50
using namespace std;

typedef __int64 LL;

int N,A[MN];
LL K;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%I64d",&N,&K);
	int p=0,t=N-1;
	for(int n=1;n<N;n++){
		LL v=(LL)1<<(N-n-1);
		if(K<=v){
			A[p]=n,p++;
		}
		else{
			K-=v;
			A[t]=n,t--;
		}
	}
	A[p]=N;
	for(int i=0;i<N;i++){
		printf("%d ",A[i]);
	}
	return 0;
}
//*/