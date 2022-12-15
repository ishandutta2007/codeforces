#include <bits/stdc++.h>
using namespace std;

int N, M, p=-1, i, x;

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<N;i++){
		scanf("%d",&x); p += x+1;
		if(p > M){printf("NO\n"); return 0;}
	}
	if(p == M) printf("YES\n");
	else printf("NO\n");
	return 0;
}