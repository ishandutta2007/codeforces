#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int MN = 1e6+6;
typedef long long ll;
ll pos[MN], arr[MN], N, i, x, _, dp[MN], bit[MN], ans;
map<ll,ll> mp;

void upd(ll p,ll v){for(;p<=N;p+=p&-p)bit[p]+=v;}
ll qu(ll p){ll r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}

int main(){
	for(scanf("%lld",&N),i=1;i<=N;i++){
		scanf("%lld",&arr[i]);
		mp[arr[i]] = 0;
	}
	auto it=mp.begin();
	for(;it!=mp.end();it++) it->second=++_;
	for(i=1;i<=N;i++) pos[i]=mp[arr[i]];
	for(i=1;i<=N;i++){
		dp[i] = qu(N)-qu(pos[i]-1);
		upd(pos[i], 1LL);
	}
	memset(bit,0,sizeof(bit));
	for(i=1;i<=N;i++){
		ans += qu(N)-qu(pos[i]-1);
		upd(pos[i], dp[i]);
	}
	printf("%lld\n",ans);
	return 0;
}