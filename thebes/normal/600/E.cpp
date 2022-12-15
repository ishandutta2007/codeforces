#include <bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
pair<int,long long> sol[MN];
int cnt[MN], n, c[MN], s[MN], i, x, y, d[MN], nxt;
vector<int> adj[MN], v[MN];

void sz(int u, int p){
	s[u] = 1;
	for(auto v : adj[u]){
		if(v == p) continue;
		sz(v,u); s[u]+=s[v];
	}
}

void solve(int n, int p, bool r){
	pair<int,int> o(-1,-1);
	for(auto v : adj[n]){
		if(v == p) continue;
		if(s[v]>o.second)
			o=make_pair(v,s[v]);
	}
	for(auto v : adj[n]){
		if(v!=p&&v!=o.first)
			solve(v,n,0);
	}
	if(o.first==-1) d[n]=nxt++;
	else{solve(o.first,n,1); sol[n]=sol[o.first]; d[n]=d[o.first];}
	v[d[n]].push_back(n); cnt[c[n]]++;
	if(cnt[c[n]]==sol[n].first) sol[n].second+=c[n];
	else if(cnt[c[n]]>sol[n].first) sol[n]={cnt[c[n]],c[n]};
	for(auto x : adj[n]){
		if(x == p || x == o.first) continue;
		for(auto i : v[d[x]]){
			cnt[c[i]]++; v[d[n]].push_back(i);
			if(cnt[c[i]]==sol[n].first) sol[n].second+=c[i];
			else if(cnt[c[i]]>sol[n].first) sol[n]={cnt[c[i]],c[i]};
		}
	}
	if(r == 0){
		for(auto i : v[d[n]])
			cnt[c[i]]--;
	}
}

int main(){
	for(scanf("%d",&n),i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(i=0;i<n-1;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	sz(1, 0); solve(1, 0, 1);
	for(i=1;i<=n;i++)
		printf("%lld ",sol[i].second);
	return 0;
}