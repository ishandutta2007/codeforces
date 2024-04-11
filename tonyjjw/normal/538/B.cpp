//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
using namespace std;

int N,L;
int A[10];
int s[10];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	int m=0;
	while(N){
		A[L]=N%10;
		if(A[L]>m)m=A[L];
		L++;N/=10;
	}
	printf("%d\n",m);
	for(int i=0;i<m;i++){
		int v=0,t=1;
		for(int j=0;j<L;j++){
			if(A[j]){
				v+=t;
				A[j]--;
			}
			t*=10;
		}
		printf("%d ",v);
	}
	return 0;
}
//*/