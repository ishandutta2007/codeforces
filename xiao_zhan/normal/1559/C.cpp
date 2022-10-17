#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[10500];

void work(int x){
	int i,j,k;
	for(i=1;i<x;i++){
		printf("%d ",i);
	}
	printf("%d ",n+1);
	for(i=x;i<=n;i++){
		printf("%d ",i);
	}
	puts("");
}

int main(){
	ios::sync_with_stdio(0);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(i=1;i<=n;i++){
			if(a[i]==1){
				work(i);goto aaa;
			}
		}
		for(i=1;i<=n+1;i++){
			printf("%d ",i);
		}
		puts("");
		aaa:;
	}
}