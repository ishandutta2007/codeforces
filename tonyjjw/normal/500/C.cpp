//*/
#include<stdio.h>
#pragma warning(disable:4996)
#define MN 5000
#define MM 10000

using namespace std;

int N,M,C,ans;
int W[MN],A[MN],ord[MN],V[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&M);
	int i,j;
	for(i=0;i<N;i++)scanf("%d",&W[i]);
	for(i=0;i<M;i++)scanf("%d",&A[i]),--A[i];
	for(i=0;i<M;i++){
		if(V[A[i]])continue;
		ord[C]=A[i];
		++C;
		V[A[i]]=1;
	}
	for(i=0;i<M;i++){
		for(j=0;j<C;j++){
			if(ord[j]==A[i])break;
		}
		int p;
		for(p=j;p>0;p--){
			ord[p]=ord[p-1];
			ans+=W[ord[p]];
		}
		ord[0]=A[i];
	}
	printf("%d",ans);
	return 0;
}
//*/