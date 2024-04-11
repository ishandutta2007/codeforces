#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int MN = 1e5+5;
typedef long long ll;
typedef pair<ll,ll> pll;
pll a[MN], b[MN];
ll N, i, x, y, w, ans;
vector<pll> adj[MN];

void solve(ll n,ll p){
	for(auto v : adj[n]){
		if(v.first==p) continue;
		solve(v.first, n);
		pll tmp={a[v.first].first+v.second,v.first};
		if(tmp.first>a[n].first) b[n]=a[n],a[n]=tmp;
		else if(tmp.first>b[n].first) b[n]=tmp;
	}
}

int main(){
	for(scanf("%lld",&N),i=1;i<N;i++){
		scanf("%lld%lld%lld",&x,&y,&w);
		adj[x].pb({y,w});
		adj[y].pb({x,w});
		ans += 2*w;
	}
	solve(1,0);
	printf("%lld\n",ans-a[1].first);
	return 0;
}