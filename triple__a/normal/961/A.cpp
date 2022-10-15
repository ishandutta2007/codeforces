#include "bits/stdc++.h"
using namespace std;

const int maxn=100007;
int n,m;
int a[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;++i){
		int t;
		scanf("%d",&t);
		a[t]++;
	}
	int ans=maxn;
	for (int i=1;i<=n;++i){
		ans=min(ans,a[i]);
	}
	printf("%d\n",ans);
	return 0;
}