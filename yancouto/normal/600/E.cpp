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

struct colors {
	map<int, int> co_qt;
	map<int, ll> qt_qt;
	void add(int co, int qt) {
		int old = co_qt[co];
		co_qt[co] += qt;
		if(old != 0) {
			qt_qt[old] -= co;
			if(qt_qt[old] == 0)
				qt_qt.erase(old);
		}
		qt_qt[old + qt] += co;
	}
	inline int size() { return co_qt.size(); }
};

void join(colors& a, colors& b) {
	if(a.size() < b.size()) {
		a.co_qt.swap(b.co_qt);
		a.qt_qt.swap(b.qt_qt);
	}
	for(pii p : b.co_qt)
		a.add(p.fst, p.snd);
	b.co_qt.clear();
	b.qt_qt.clear();
}

vector<int> adj[100009];
ll ans[100009]; int c[100009];
colors cs[100009];
void dfs(int u, int p) {
	colors &x = cs[u];
	x.add(c[u], 1);
	for(int v : adj[u]) {
		if(v == p) continue;
		dfs(v, u);
		join(x, cs[v]);
	}
	ans[u] = x.qt_qt.rbegin()->snd;
}

int main() {
	int i, n, a, b;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &c[i]);
	for(i = 0; i < n - 1; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(0, -1);
	for(i = 0; i < n; i++)
		printf("%I64d ", ans[i]);
	putchar('\n');
}