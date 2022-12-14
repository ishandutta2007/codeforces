//*

#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
#define MK 5
#define MN 1000

int N,K;
int A[MK][MN],pos[MK][MN+1];
int D[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	int i,j,k,ans=0;
	scanf("%d%d",&N,&K);
	for(i=0;i<K;i++){
		for(j=0;j<N;j++){
			scanf("%d",&A[i][j]),--A[i][j];
			pos[i][A[i][j]]=j;
		}
	}
	for(i=0;i<N;i++){
		D[i]=1;
		for(j=0;j<i;j++){
			for(k=0;k<K;k++){
				if(pos[k][A[0][i]]<pos[k][A[0][j]])break;
			}
			if(k==K && D[i]<D[j]+1)D[i]=D[j]+1;
		}
		if(ans<D[i])ans=D[i];
	}
	printf("%d",ans);
	return 0;
}

//*/