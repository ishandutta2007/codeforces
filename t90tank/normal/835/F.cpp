#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
#define fir first
#define sec second 

const int maxn = 300000; 
const int maxe = 900000; 
const ll oo = 0x3f3f3f3f3f3f3f3fll; 

struct edge { 
	int t, w, nxt;
}es[maxe]; 
int hd[maxn];
int n, m, tot;  
//

void add_(int a, int b, int c) {
	es[++tot] = {b, c, hd[a]}; 
	hd[a] = tot;  
}
void add(int a, int b, int c = 0) {
	add_(a,b,c); 
	add_(b,a,c); 
}

void init() {
	cin>>n; 
	tot = 1; 
	fill(hd, hd+n+1, 0); 
	for (int i = 1; i <= n; ++i) {
		int a, b, c; 
		cin>>a>>b>>c; 
		add(a, b, c); 
	}
}

int fa[maxn], vis[maxn]; 
vector<pair<int,int> > loop;
int rt;  

bool findloop(int u) {
	vis[u] = 1;
	bool rr = false;  
	for (int i = hd[u]; i; i = es[i].nxt) 
		if (i != fa[u]) {
			int v = es[i].t;
			if (vis[v] == 0) {
				fa[v] = i^1;
				rr = (rr || findloop(v));
			} 
			else if (vis[v] == 1) {
				rt = v; 
				rr = true; 
				loop.push_back({v, i^1}); 
			} 
		}
	vis[u] = 2; 
	if (u == rt) rr = false; 
	if (rr) loop.push_back({u, fa[u]}); 
	return rr; 
};

ll len[maxn], sum[maxn], fur[maxn], tans; 

void dfs(int u) {
	vis[u] = 1; 
	len[u] = 0; 
	for (int i = hd[u]; i; i = es[i].nxt) {
		int v = es[i].t; 
		if (!vis[v]) {
			dfs(v); 
			tans = max(tans, len[u]+len[v]+es[i].w); 
			len[u] = max(len[u], len[v] + es[i].w); 
		}
	}
}

void ring_tree() {
	fill(vis, vis+n+1, 0); 
	loop.clear();
	rt = 0; fa[1] = 0; 
	findloop(1); 
	fill(vis, vis+n+1, 0);
	//for (uint i = 0; i < loop.size(); ++i) cout<<"("<<loop[i].first<<","<<es[loop[i].second].t<<")"<<endl; 
	tans = 0; 
	for (int i = 0; i < loop.size(); ++i) vis[loop[i].fir] = 1; 
	for (int i = 0; i < loop.size(); ++i) dfs(loop[i].fir);
}

ll maxl[maxn], maxr[maxn], maxll[maxn], maxrr[maxn], maxlr[maxn], maxrl[maxn]; 

void solve() {
	sum[0] = 0; sum[1] = 0; 
	int s = 0; 
	int lenloop = loop.size(); 
	for (int i = 0; i < lenloop; ++i) {
		fur[++s] = len[loop[i].fir];
		sum[s+1] = sum[s] + es[loop[i].sec].w;
	}
	maxl[0]=maxll[0]=maxlr[0]=maxr[lenloop+1]=maxrr[lenloop+1]=maxrl[lenloop+1] = -oo; 
	for (int i = 1; i <= lenloop; ++i) {
		maxl[i] = max(maxl[i-1], sum[i]+fur[i] ); 
		maxll[i] = max(maxll[i-1], sum[i]+fur[i]+maxlr[i-1]); 
		maxll[i] = max(maxll[i], fur[i]); 
		maxlr[i] = max(maxlr[i-1], -sum[i]+fur[i] ); 
	}
	for (int i = lenloop; i >= 1; --i) {
		maxr[i] = max(maxr[i+1], -sum[i]+fur[i] ); 
		maxrr[i] = max(maxrr[i+1], -sum[i]+fur[i]+maxrl[i+1]);
		maxrr[i] = max(maxrr[i], fur[i]);  
		maxrl[i] = max(maxrl[i+1], sum[i]+fur[i] ); 
	}
	ll ans = maxll[lenloop]; 
	for (int i = 1; i < lenloop; ++i) 
		ans = min(ans, max(max(maxll[i], maxrr[i+1]), maxl[i]+maxr[i+1]+sum[lenloop+1])); 
	cout<<max(tans,ans)<<endl; 
}

int main() {
	init(); 
	ring_tree(); 
	solve(); 
}