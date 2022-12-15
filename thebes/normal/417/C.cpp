#include <bits/stdc++.h>
using namespace std;

int N, K, i, j;

int main(){
	scanf("%d%d",&N,&K);
	if(K > (N-1)/2) printf("-1\n");
	else{
		printf("%d\n",N*K);
		for(i=0;i<N;i++){
			for(j=1;j<=K;j++)
				printf("%d %d\n",i+1,(i+j)%N+1);
		}
	}
	return 0;
}