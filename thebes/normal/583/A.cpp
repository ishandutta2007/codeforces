#include <bits/stdc++.h>
using namespace std;

int a[51], b[51], N, i, x, y;

int main(){
	for(scanf("%d",&N),i=1;i<=N*N;i++){
		scanf("%d%d",&x,&y);
		if(!a[x] && !b[y]){
			printf("%d ",i);
			a[x]=b[y]=1;
		}
	}
	return 0;
}