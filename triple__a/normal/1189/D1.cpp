#include<bits/stdc++.h>
using namespace std;

const int maxn=1000007;
int main(){
	int a[maxn],n;
	scanf("%d",&n);
	if (n==2){
		printf("yes");
		return 0;
	}
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		a[u]++,a[v]++;
	}
	for (int i=1;i<=n;++i){
		if (a[i]==2){
			printf("no");
			return 0;
		}
	}
	printf("yes");
	return 0;
}