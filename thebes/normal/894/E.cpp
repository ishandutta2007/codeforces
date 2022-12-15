#include <bits/stdc++.h>
using namespace std;

typedef long long ll; const ll MN = 1000006;
struct pii{ll f, s;}vs[MN]; vector<pii> adj[MN], c[MN];
pii pr(ll f,ll s){pii p={f,s}; return p;}
ll N, M, S, C, i, j, x, y, w, sz[MN], st[MN], cmp[MN], dp[MN];
stack<ll> s;

void dfs(ll u){
	vs[u].f=vs[u].s=++j; st[u]=1; s.push(u);
	for(auto v : adj[u]){
		if(!vs[v.f].f){dfs(v.f); vs[u].s=min(vs[u].s,vs[v.f].s);}
		else if(st[v.f]) vs[u].s=min(vs[u].s,vs[v.f].f);
	}
	if(vs[u].f==vs[u].s){
		while(s.size() && s.top() != u){
			st[s.top()]=0; cmp[s.top()]=C+1; s.pop();
		}
		st[s.top()]=0; cmp[s.top()]=++C; s.pop();
	}
}

ll sum(ll x){
	ll lo = 0, hi = 35000;
	while(lo != hi){
		ll m = (lo+hi)/2;
		if(m*(m+1)/2<=x) lo=m+1;
		else hi=m;
	}
	return (--hi+1)*x-(hi)*(hi+1LL)*(hi+2LL)/6;
}

void solve(ll n, ll p){
	if(st[n]) return; else st[n]=1;
	for(auto v : c[n]){
		if(v.f == p) continue;
		solve(v.f, n); dp[n]=max(dp[n],dp[v.f]+v.s);
	}
	dp[n] += sz[n];
}

int main(){
	for(scanf("%lld%lld",&N,&M),i=0;i<M;i++){
		scanf("%lld%lld%lld",&x,&y,&w);
		adj[x].push_back(pr(y,w));
	}
	for(i=1;i<=N;i++){
		if(!vs[i].f) dfs(i);
	}
	for(i=1;i<=N;i++){
		for(auto v : adj[i]){
			if(cmp[i]==cmp[v.f]) sz[cmp[i]] += sum(v.s);
			else c[cmp[i]].push_back(pr(cmp[v.f],v.s));
		}
	}
	scanf("%lld",&S); solve(cmp[S],-1);
	printf("%lld\n",dp[cmp[S]]);
	return 0;
}