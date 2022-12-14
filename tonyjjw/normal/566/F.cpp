#include<stdio.h>
#pragma warning(disable:4996)
#define MN 1000000

int A[MN];
int D[MN];
int v[MN+1];
int N;

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d",&N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	int ans=0;
	for(int i=0;i<N;i++){
		D[i]=v[A[i]]+1;
		for(int j=A[i];j<=MN;j+=A[i]){
			if(v[j]<D[i])v[j]=D[i];
		}
		if(ans<D[i])ans=D[i];
	}
	printf("%d",ans);
	return 0;
}