#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1000009;

int n, m;
inline int id(int i, int j) { return i*m + j;; }

int M[N];
map<int, vector<int>> mp;

int S[N], sz[N];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
void join(int a, int b) {
	if((a = find(a)) == (b = find(b))) return;
	if(sz[a] < sz[b]) swap(a, b);
	S[b] = a;
	sz[a] += sz[b];
}

int d[N], low[N], deg[N];
int st[N], sn;
int seen[N], tempo;
vector<int> adj[N], adj2[N], ver[N];
void dfs(int u) {
	//printf("dfs(%d)\n", u);
	if(seen[u]) return;
	//printf("cont\n");
	seen[u] = true;
	d[u] = low[u] = tempo++;
	//printf("%d: d%d low%d\n", u, d[u], low[u]);
	st[sn++] = u;
	for(int v : adj[u]) {
		//printf("anal %d->%d\n", u, v);
		if(seen[v]) low[u] = min(low[u], d[v]);
		else { dfs(v); low[u] = min(low[u], low[v]); }
	}
	//printf("%d: d%d low%d\n", u, d[u], low[u]);
	if(low[u] >= d[u]) {
		//printf("new comp:");
		int a = -1;
		while(a != u) {
			a = st[--sn];
			//printf(" %d", a);
			join(a, u);
			low[a] = INT_MAX;
			d[a] = INT_MAX;
		}
		//putchar('\n');
	}
}

int val[N];

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < N; i++) S[i] = i, sz[i] = 1;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &M[id(i, j)]);
	for(i = 0; i < n; i++) {
		mp.clear();
		for(j = 0; j < m; j++)
			mp[M[id(i, j)]].pb(id(i, j));
		for(auto it = mp.begin(); it != mp.end(); ++it) {
			vector<int> &v = it->snd;
			for(j = 0; j < v.size() - 1; j++)
				adj[v[j]].pb(v[j + 1]);
			if(v.size() > 1) adj[v.back()].pb(v.front());
			if(next(it) != mp.end()) adj[v.back()].pb(next(it)->snd.front());
		}
	}
	for(i = 0; i < m; i++) {
		mp.clear();
		for(j = 0; j < n; j++)
			mp[M[id(j, i)]].pb(id(j, i));
		for(auto it = mp.begin(); it != mp.end(); ++it) {
			vector<int> &v = it->snd;
			for(j = 0; j < v.size() - 1; j++)
				adj[v[j]].pb(v[j + 1]);
			if(v.size() > 1) adj[v.back()].pb(v.front());
			if(next(it) != mp.end()) adj[v.back()].pb(next(it)->snd.front());
		}
	}
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			dfs(id(i, j));
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			ver[find(id(i, j))].pb(id(i, j));
			for(int x : adj[id(i, j)]) {
				if(find(x) == find(id(i, j))) continue;
				adj2[find(id(i, j))].pb(find(x));
				deg[find(x)]++;
			}
		}
	vector<int> d0;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(id(i, j) == find(id(i, j)) && deg[id(i, j)] == 0)
				d0.pb(id(i, j));
	for(i = 1; !d0.empty(); i++) {
		vector<int> nd;
		for(int u : d0) {
			for(int v : ver[u]) val[v] = i;
			for(int v : adj2[u])
				if(v != u && (--deg[v]) == 0)
					nd.pb(v);
		}
		d0.swap(nd);
	}
	
	for(i = 0; i < n; i++) {
		for(j = 0; j < m; j++)
			printf("%d ", val[id(i, j)]);
		putchar('\n');
	}
}