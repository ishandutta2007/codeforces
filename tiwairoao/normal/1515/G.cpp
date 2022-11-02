#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;

struct edge{int x, l;};
std::vector<edge>G1[N + 5], G2[N + 5];
void adde(int u, int v, int w) {
	G1[u].push_back((edge){v, w});
	G2[v].push_back((edge){u, w});
}

std::vector<int>v[N + 5];
int dfn[N + 5], low[N + 5], dcnt;
int id[N + 5], cnt, stk[N + 5], tp;
void dfs(int x) {
	dfn[x] = low[x] = (++dcnt), stk[++tp] = x;
	for (auto to : G1[x]) {
		if (!dfn[to.x]) {
			dfs(to.x), low[x] = std::min(low[x], low[to.x]);
		} else if (!id[to.x]) {
			low[x] = std::min(low[x], dfn[to.x]);
		}
	}
	if (dfn[x] == low[x]) {
		cnt++;
		do {
			id[stk[tp]] = cnt, v[cnt].push_back(stk[tp]);
		} while (stk[tp--] != x);
	}
}

ll gcd(ll x, ll y) {return (y == 0) ? x : gcd(y, x % y);}

ll d1[N + 5], d2[N + 5];
void dfs1(int x, int i) {
	for (auto e : G1[x]) if (id[e.x] == i && d1[e.x] == -1)
		d1[e.x] = d1[x] + e.l, dfs1(e.x, i);
}
void dfs2(int x, int i) {
	for (auto e : G2[x]) if (id[e.x] == i && d2[e.x] == -1)
		d2[e.x] = d2[x] + e.l, dfs2(e.x, i);
}

ll f[N + 5]; int n, m, q;
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, a, b, l; i <= m; i++)
		scanf("%d%d%d", &a, &b, &l), adde(a, b, l);
	for (int i = 1; i <= n; i++) if (!dfn[i]) dfs(i);

	for (int i = 1; i <= cnt; i++) {
		f[i] = 0;
		for (auto x : v[i]) d1[x] = d2[x] = -1;
		d1[v[i][0]] = 0, dfs1(v[i][0], i);
		d2[v[i][0]] = 0, dfs2(v[i][0], i);
		for (auto x : v[i]) for (auto e : G1[x]) if (id[e.x] == i)
			f[i] = gcd(f[i], d1[x] + e.l + d2[e.x]);
	}

	scanf("%d", &q);
	for (int i = 1, v, s, t; i <= q; i++) {
		scanf("%d%d%d", &v, &s, &t);
		puts(gcd(s, t) % gcd(f[id[v]], t) == 0 ? "YES" : "NO");
	}
}