#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

inline int read () {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

#define ll long long
#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 300300;

int n, m; ll a[MAXN], x;

namespace dsu {
	int fa[MAXN];
	int gf (int x) { return fa[x] == x ? x : (fa[x] = gf(fa[x])); }
}

struct expq {
	struct inpq {
		ll val; int id;
		bool operator < (const inpq &tmp) const { return val == tmp.val ? (id < tmp.id) : (val < tmp.val); }
		bool operator == (const inpq &tmp) const { return val == tmp.val && id == tmp.id; }
	};
	priority_queue <inpq> val, rem;
	void push (ll v, int i) { val.push({v, i}); }
	void del (ll v, int i) { rem.push({v, i}); }
	void upd () { while (!val.empty() && !rem.empty() && val.top() == rem.top()) val.pop(), rem.pop(); }
	int top () { upd(); return val.top().id; }
	int size () { upd(); return val.size() - rem.size(); }
} pq;
vector <pii> E[MAXN];

int main () {
	n = read(), m = read(), x = read(); int i, j; ll s = 0;
	for (i = 1; i <= n; i++) a[i] = read(), pq.push(a[i], i), dsu::fa[i] = i, s += a[i];
	for (i = 1; i <= m; i++) {
		int u = read(), v = read();
		E[u].push_back(make_pair(v, i)); E[v].push_back(make_pair(u, i));
	}
	if (s < 1ll * (n - 1) * x) { puts("NO"); return 0; }
	puts("YES");
	while (pq.size() > 1) {
		int u = pq.top(); pq.del(a[u], u);
		int v = dsu::gf(E[u].back().fr);
        while (u == v) E[u].pop_back(), v = dsu::gf(E[u].back().fr);
        printf("%d\n", E[u].back().se);
        pq.del(a[v], v);
		if (E[u].size() < E[v].size()) swap(u, v);
		a[u] = a[u] + a[v] - x;
		dsu::fa[v] = u; pq.push(a[u], u);
		while (!E[v].empty()) {
			if (dsu::gf(E[v].back().fr) != u) E[u].push_back(E[v].back());
			E[v].pop_back();
		}
	}
	return 0;
}