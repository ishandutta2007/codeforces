#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k, _, lo, hi;

int main(){
	scanf("%lld%lld%lld",&n,&_,&k);
	lo = 1; hi = 1e9+10;
	while(lo<hi){
		ll m=lo+hi>>1;
		ll idk = -m;
		if(m<=k) idk+=m*(m+1)/2+k-m;
		else idk+=m*(m+1)/2-(m-k)*(m-k+1)/2;
		if(n-k+1>=m) idk+=m*(m+1)/2+n-k-m+1;
		else idk+=m*(m+1)/2-(m-n+k-1)*(m-n+k)/2;
		if(idk>_) hi=m;
		else lo=m+1;
	}
	printf("%lld\n",lo-1);
	return 0;
}