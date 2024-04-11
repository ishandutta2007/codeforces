#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MN = 1e5+5;
ll a[MN], b[MN], lo, hi, N, M, i;

ll f(ll m){
	ll ret = 0;
	for(ll i=1;i<=N;i++)
		ret += max(0LL,m-a[i]);
	for(ll i=1;i<=M;i++)
		ret += max(0LL,b[i]-m);
	return ret;
}

int main(){
	for(scanf("%lld%lld",&N,&M),i=1;i<=N;i++)
		scanf("%lld",&a[i]);
	for(i=1;i<=M;i++) scanf("%lld",&b[i]);
	lo = 0; hi = 1e14+10;
	while(lo+3 < hi){
		ll l = (2*lo+hi)/3;
		ll r = (lo+2*hi)/3;
		if(f(l) <= f(r)) hi=r;
		else lo=l;
	}
	ll ans = 1LL<<60;
	while(lo<=hi){ans=min(ans,f(lo));lo++;}
	printf("%lld\n",ans);
	return 0;
}