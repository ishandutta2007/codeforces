#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, q, i, j, ans, x, cnt[32];

int main(){
	for(scanf("%lld%lld",&n,&q),i=1;i<=n;i++){
		scanf("%lld",&x);
		for(j=31;j>=0;j--){
			if((1LL<<j)&x) cnt[j]++;
		}
	}
	for(;q;q--){
		scanf("%lld",&x); ans=0;
		for(i=31;i>=0;i--){
			ll d=min(cnt[i],x/(1LL<<i));
			ans+=d; x-=d*(1LL<<i);
		}
		if(!x) printf("%lld\n",ans);
		else printf("-1\n");
	}
	return 0;
}