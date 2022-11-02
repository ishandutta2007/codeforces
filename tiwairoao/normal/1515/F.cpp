#include <bits/stdc++.h>

typedef long long ll;

const int N = 300000;

struct edge{
	int to, id; edge *nxt;
}edges[3*N + 5], *hd[N + 5], *tl[N + 5], *ecnt = edges;
void adde(int u, int v, int i) {
	edge *p = (++ecnt), *q = (++ecnt);
	(*p) = {v, i, NULL}, tl[u]->nxt = p, tl[u] = p;
	(*q) = {u, i, NULL}, tl[v]->nxt = q, tl[v] = q;
}

ll a[N + 5]; int fa[N + 5], n, m, x;
int find(int u) {if (fa[u] == u) return u; else return fa[u] = find(fa[u]);}
void unite(int u, int v) {
	int fu = find(u), fv = find(v);
	assert (a[fu] + a[fv] >= x);
	fa[fu] = fv, a[fv] += a[fu] - x;
	tl[fv]->nxt = hd[fu]->nxt;
	if (hd[fu]->nxt) tl[fv] = tl[fu];
}

int main() {
	ll s = 0; scanf("%d%d%d", &n, &m, &x);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]), s += a[i];
		hd[i] = tl[i] = (++ecnt), fa[i] = i;
	}
	for (int i = 1, u, v; i <= m; i++)
		scanf("%d%d", &u, &v), adde(u, v, i);
	
	if (s < (ll)(n - 1) * x) {
		puts("NO");
	} else {
		puts("YES");
		std::set<std::pair<ll, int> >st;
		for (int i = 1; i <= n; i++) st.insert(std::make_pair(a[i], i));
		for (int i = 1; i < n; i++) {
			int x = st.rbegin()->second; st.erase(std::make_pair(a[x], x));
			while (hd[x]->nxt && find(hd[x]->nxt->to) == find(x))
				hd[x]->nxt = hd[x]->nxt->nxt;
			assert (hd[x]->nxt);

			printf("%d\n", hd[x]->nxt->id);

			int y = find(hd[x]->nxt->to); st.erase(std::make_pair(a[y], y));
			unite(y, x), st.insert(std::make_pair(a[x], x));
		}
	}
	return 0;
}