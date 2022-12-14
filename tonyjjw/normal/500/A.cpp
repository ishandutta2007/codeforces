//*/
#include<stdio.h>
#define MN 50000
//#pragma warning(disable:4996)

int N,T;
int V[MN],A[MN];

int main(){
//	freopen("input.txt","r",stdin),freopen("output.txt","w",stdout);
	scanf("%d%d",&N,&T);
	int i;
	for(i=0;i<N-1;i++)scanf("%d",&A[i]);
	V[0]=1;
	for(i=0;i<T;i++){
		if(!V[i])continue;
		V[i+A[i]]=1;
	}
	if(V[T-1])puts("YES");
	else{
		puts("NO");
	}
	return 0;
}
//*/