//*
#include<stdio.h>
#include<tuple>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
#define pb push_back
#define eb emplace_back
#define mt make_tuple
#define MN 200000+1
using namespace std;

int N;
int A[MN];
int S[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	for(int i=1;i<N;i++){
		for(int k=1;k<=N-1;k++){
			int r=(i-1)/k;
			int s,t;
			s=(i+r)/(r+1);
			if(!r){
				t=N-1;
			}
			else{
				t=(i-1)/r;
			}
			if(A[i]<A[r]){
				S[s]++;
				S[t+1]--;
			}
			k=t;
		}
	}
	for(int i=1;i<=N-1;i++)S[i]+=S[i-1];
	for(int i=1;i<=N-1;i++)printf("%d ",S[i]);
	return 0;
}
//*/