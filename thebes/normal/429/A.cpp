#include <bits/stdc++.h>
#define gl(x) getline(cin,x)
#define gc(x) cin.get(x)
#define sz(x) (int)(x.size())
#define al(x) (x).begin(),(x).end()
#define ms(a, b) memset(a,b,sizeof(a))
#define sp ' '
#define nl '\n'
#define fi first
#define se second
#define lsb(x) ((x)&(-x))
using namespace std;
void sc(){}template<class T,class...A>void sc(T&t,A&...a){cin>>t,sc(a...);}
void pr(){}template<class T,class...A>void pr(T t,A...a){cout<<t,pr(a...);}
typedef long long ll;
typedef pair<int, int> pi;
typedef double db;
typedef long double ld;

const int N = 1e5 + 5;
vector<int> adj[N], ndj[2][N], d(N);
vector<bool> init(N), goal(N), g(N);

void dfs(int v = 1, int p = -1, int gp = -1) {
	if(d[v] & 1) g[v] = true;
	if(gp != -1) {
		ndj[d[v] & 1][v].push_back(gp);
		ndj[d[v] & 1][gp].push_back(v);
	}
	for(int i : adj[v]) {
		if(i == p) continue;
		d[i] = d[v] + 1; dfs(i, v, p);
	}
}

vector<bool> vis(N);
vector<int> ans;
void go(int v, bool sw = false) {
	//pr("GO ", v, sp, sw, nl, '\t', init[v], sp, sw ^ goal[v], nl);
	vis[v] = true;
	if(init[v] != (sw ^ goal[v])) sw = !sw, ans.push_back(v);
	for(int i : ndj[g[v]][v]) {
		if(vis[i] || d[i] < d[v]) continue; go(i, sw);
	}
}

void trv(int v = 1, int p = -1) {
	if(!vis[v]) go(v);
	for(int i : adj[v]) {
		if(i == p) continue; 
		trv(i, v);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; sc(n);
	for(int i = 1; i < n; i++) {
		int u, v; sc(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {int x; sc(x); init[i] = x;}
	for(int i = 1; i <= n; i++) {int x; sc(x); goal[i] = x;}
	dfs(); trv();
	pr(sz(ans), nl); for(int i : ans) pr(i, nl);
}