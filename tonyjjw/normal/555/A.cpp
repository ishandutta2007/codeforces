//*
#include<stdio.h>
#pragma warning(disable:4996)
using namespace std;
#define MN 100000

int N,K;
int A[MN];

int chk(int l,int r){
	return (l+1)!=r;
}

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int m,l,r,val;
	int gn,ans=0;
	scanf("%d%d",&N,&K);
	gn=K;
	for(int i=1;i<=K;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++)scanf("%d",&A[j]);
		if(A[0]==1){
			val=m;
			for(int j=1;j<m;j++){
				if(A[j]!=j+1){
					val=j;
					break;
				}
			}
		}
	}
	ans=(N-val+1-K)+(N-val);
	printf("%d",ans);
	return 0;
}
//*/