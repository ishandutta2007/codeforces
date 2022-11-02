// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
#define MP make_pair
typedef long long ll;
typedef unsigned long long ull;
const ll INF=1e18;
int n,m,s,t,cur[1010];
int level[1010],tot;
ll ans,flow[1000000],val[1010],v2[1010];
int head[1010],nxt[1000000];
int to[1000000];
queue<int> q;
vector<int> V;
void init() {
	for (int i=0;i<V.size();i++) head[V[i]]=0;
	tot=1;	
}
void Add_edge(int a,int b,ll c) {
	tot++; nxt[tot]=head[a];
	head[a]=tot; to[tot]=b; flow[tot]=c;
}
void add_edge(int a,int b,ll c) {
	Add_edge(a,b,c);
	Add_edge(b,a,0);
}
bool bfs() {
	q=queue<int>();
	for (int i=0;i<V.size();i++) cur[V[i]]=head[V[i]],level[V[i]]=-1;
	q.push(s);
	level[s]=0;
	while (!q.empty()) {
		int a=q.front(),b; q.pop();
		for (register int i=head[a];i;i=nxt[i]) {
			b=to[i];
			if (flow[i]>0&&level[b]==-1) {
				level[b]=level[a]+1;
				q.push(b);
			}
		}
	}
	return level[t]!=-1;
}
ll dfs(int x,ll rest) {
	if (x==t) return rest;
	ll used=0;
	for (register int i=cur[x];i;i=nxt[i]) {
		cur[x]=i;
		int y=to[i];
		if (flow[i]>0&&level[y]==level[x]+1) {
			ll tflow=dfs(y,min(flow[i],rest-used));
			used+=tflow;
			flow[i]-=tflow;
			flow[i^1]+=tflow;
			if (rest-used==0) break;
		}
	}
	if (!used) level[x]=-1;
	return used;
}
void Dinic() {
	while (bfs()) dfs(s,INF);
}
bool vis[1010];
void dfs(int x) {
	if (vis[x]) return;
	vis[x]=1;
	for (int i=head[x],y;i;i=nxt[i]) {
		y=to[i];
		if (flow[i]) dfs(y);
	}
}
ll sqr(ll x) { return x*x; }
void solve(vector<int> v,vector<pair<int,int> > e,int l,int r) {
	if (v.empty()) return;
	if (l==r) {
		for (int i=0;i<v.size();i++)
			v2[v[i]]=l;
		return;
	}
	int mid=(l+r)/2;
	s=n+1,t=n+2;
	V=v; V.push_back(s); V.push_back(t);
	init();
	ll tmp;
	for (int i=0;i<v.size();i++) {
		tmp=abs(val[v[i]]-mid)-abs(val[v[i]]-(mid+1));
		if (tmp>0) add_edge(s,v[i],tmp);
		else add_edge(v[i],t,-tmp);
	}
	for (int i=0;i<e.size();i++) add_edge(e[i].first,e[i].second,INF);
	
	Dinic();
	
	for (int i=0;i<V.size();i++) vis[V[i]]=0;
	dfs(s);
	vector<int> v0,v1; v0.clear(); v1.clear();
	vector<pair<int,int> > e0,e1; e0.clear(); e1.clear();
	for (int i=0;i<v.size();i++)
		if (!vis[v[i]]) v0.push_back(v[i]);
		else v1.push_back(v[i]);
	int x,y;
	for (int i=0;i<e.size();i++) {
		x=e[i].first,y=e[i].second;
		if (vis[x]==vis[y]) {
			if (!vis[x]) e0.push_back(e[i]);
			else e1.push_back(e[i]);
		}
	}
	solve(v0,e0,l,mid);
	solve(v1,e1,mid+1,r);
}

int main() {
	read(n),read(m); int x,y;
	for (int i=1;i<=n;i++) read(val[i]);
	vector<int> V; vector<pair<int,int> > E;
	for (int i=1;i<=n;i++) V.push_back(i);
	for (int i=1;i<=m;i++) read(x),read(y),E.push_back(MP(x,y));
	solve(V,E,0,1e9);
	for (int i=1;i<=n;i++) printf("%lld ",v2[i]); puts("");
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/