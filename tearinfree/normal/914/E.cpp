#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <functional>
#include <cmath>
#include <stack>
#include <iostream>
#include <cstring>

using namespace std;
typedef long long lli;
typedef pair<int,int> pii;
typedef pair<lli,int> pli;
typedef pair<lli,lli> pll;

int n;
vector<int> adj[200001];
char str[202001];

int vis[200001],sz[200001];

lli cnt[1<<20],ans[200001];
int cc[1<<20],g=1;

int getsz(int cur,int p) {
	sz[cur]=1;
	for(auto &it:adj[cur]) if(it!=p && !vis[it]){
		sz[cur]+=getsz(it,cur);
	}
	return sz[cur];
}
int getCent(int cur,int p,int s) {
	int f=0,id=-1;
	for(auto &it:adj[cur]) if(it!=p && !vis[it] && sz[it]>=s) {
		f=1; id=it;
	}
	if(!f) return cur;
	return getCent(id,cur,s);
}
lli dfs1(int cur,int p,int state) {
	int val;
	lli res=0;
	state ^= 1 << (str[cur]-'a');
	for(int i=0;i<20;i++) {
		val = state ^ (1<<i);
		if(cc[val]==g) res+=cnt[val];
	}
	val = state;
	if(cc[val]==g) res += cnt[val];
	for(auto &it:adj[cur]) if(it!=p && !vis[it]) {
		res += dfs1(it,cur,state);
	}
	ans[cur] += res;
	return res;
}
void dfs2(int cur,int p,int state){
	state ^= 1 << (str[cur]-'a');
	if(cc[state]!=g) cc[state]=g,cnt[state]=0;
	++cnt[state];
	for(auto &it:adj[cur]) if(it!=p && !vis[it]) {
		dfs2(it,cur,state);
	}
}
void getAns(int cur) {
	int v=1 << (str[cur]-'a'),val;
	
	lli res=0;
	cc[v]=++g;
	cnt[v]=1;
	for(int i=0;i<(int)adj[cur].size();i++) {
		if(vis[adj[cur][i]])continue;
		res += dfs1(adj[cur][i],cur,0);
		dfs2(adj[cur][i],cur,v);
	}
	++g;
	for(int i=(int)adj[cur].size()-1;i>=0;i--) {
		if(vis[adj[cur][i]])continue;
		res += dfs1(adj[cur][i],cur,0);
		dfs2(adj[cur][i],cur,v);
	}
	for(int i=0;i<20;i++) {
		val = 1<<i;
		if(cc[val] == g) res += cnt[val];
	}
	val = 0;
	if(cc[val] == g) res += cnt[val];

	ans[cur] += res/2;
}
void makeCent(int cur) {
	getsz(cur,0);
	cur=getCent(cur,0,sz[cur]/2+1);
	
	getAns(cur);
	vis[cur]=1;
	for(auto &it:adj[cur]) if(!vis[it]) makeCent(it);
}

int main() {
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		scanf("%d%d",&u,&v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	scanf("%s",str+1);

	makeCent(1);
	for(int i=1;i<=n;i++) printf("%lld ",ans[i]+1);

	return 0;
}