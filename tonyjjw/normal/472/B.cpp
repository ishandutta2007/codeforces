//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
#define MN 2000
using namespace std;

int N,K;
int A[MN],ans;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A,A+N);
	for(i=N-1;i>=0;i-=K){
		ans+=2*(A[i]-1);
	}
	printf("%d",ans);
	return 0;
}

//*/