#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

int n, cnt[105], i, x, ans;
int main(){
	for(scanf("%d",&n),i=1;i<=n;i++){
		scanf("%d",&x);
		cnt[x] ++;
	}
	for(i=1;i<=100;i++)
		ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}