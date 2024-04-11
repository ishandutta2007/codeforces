#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MN = 1e6+6;
ll n, arr[MN], i, ans, a[MN], cnt[MN], bit[MN];
map<ll,ll> mp;

void upd(ll p){for(;p<=n;p+=p&-p)bit[p]++;}
ll qu(ll p){ll r=0;for(;p;p-=p&-p)r+=bit[p];return r;}

int main(){
	for(scanf("%lld",&n),i=1;i<=n;i++)
		scanf("%lld",&arr[i]),mp[arr[i]]=0;
	i=1; auto it=mp.begin();
	for(;it!=mp.end();it++) it->second=i++;
	for(i=1;i<n;i++) {
		ll idx = mp[arr[i]];
		a[i] = ++cnt[idx];
	}
	memset(cnt, 0, sizeof(cnt));
	for(i=n-1;i>=1;i--) {
		ll idx = mp[arr[i+1]];
		upd(++cnt[idx]);
		ans += qu(a[i]-1);
	}
	printf("%lld\n",ans);
	return 0;
}