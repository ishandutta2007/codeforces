#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

struct ed {
	int i, j, x;
	bool operator < (ed o) const { return x < o.x; }
};


int S[2009], sz[2009];
int find(int i) {
	if(S[S[i]] != S[i]) S[i] = find(S[i]);
	return S[i];
}
void join(int a, int b) {
	a = find(a); b = find(b);
	if(a == b) return;
	if(sz[a] < sz[b]) swap(a, b);
	sz[a] += sz[b];
	S[b] = a;
}
int d[2004][2004];
ll md[2004][2004];
vector<pii> adj[2004];

void dfs(int ini, int u, int p, ll d) {
	md[ini][u] = d;
	for(pii e : adj[u])
		if(e.fst != p)
			dfs(ini, e.fst, u, d + ll(e.snd));
}

ed es[2003*2003];

int main() {
	int i, n, j, en = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf("%d", &d[i][j]);
			if(d[i][j] && i > j) es[en++] = {i, j, d[i][j]};
		}
	sort(es, es + en);
	for(i = 0; i < n; i++)
		S[i] = i, sz[i] = 1;
	for(i = 0; i < en; i++) {
		ed e = es[i];
		if(find(e.i) == find(e.j)) continue;
		join(e.i, e.j);
		adj[e.i].pb(pii(e.j, e.x));
		adj[e.j].pb(pii(e.i, e.x));
	}
	for(i = 0; i < n; i++)
		dfs(i, i, i, 0);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(ll(d[i][j]) != md[i][j] || (!d[i][j] && i != j)) {
				puts("NO");
				return 0;
			}
	puts("YES");
}