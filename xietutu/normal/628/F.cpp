#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 20020;
struct edge {
	int v, f;
	edge* next, *op;
} ES[maxn * 10], *tot[maxn];
int S, T, EC, flow, N, n, b, q;
int h[maxn], vh[maxn];
pii a[maxn];
inline void add(int u, int v, int f) {
	ES[++EC].v = v; ES[EC].f = f; ES[EC].next = tot[u]; ES[EC].op = ES + EC + 1; tot[u] = ES + EC;
	ES[++EC].v = u; ES[EC].f = 0; ES[EC].next = tot[v]; ES[EC].op = ES + EC - 1; tot[v] = ES + EC;
}
int aug(int u, int m) {
	if (u == T) return m;
	int d = m;
	for (edge* e = tot[u]; e; e = e->next) {
		if (e->f && h[u] == h[e->v] + 1) {
			int f = aug(e->v, min(e->f, d));
			e->f -= f; e->op->f += f; d -= f;
			if (h[S] == T || !d) return m - d;
		}
	}
	int w = d < m ? min(T, h[u] + 2) : T;
	for (edge* e = tot[u]; e; e = e->next)
		if (e->f) w = min(w, h[e->v] + 1);
	++vh[w];
	--vh[h[u]] ? h[u] = w: h[S] = T;
	return m - d;
}
void maxflow() {
	vh[0] = T;
	while (h[S] != T) flow += aug(S, INT_MAX);
}
int main() {
	scanf("%d%d%d", &n, &b, &q);
	for (int i = 1; i <= q; ++i)
		scanf("%d%d", &a[i].first, &a[i].second);
	sort(a + 1, a + q + 1);
	bool flag = true;
	for (int i = 2; i <= q; ++i)
		if (a[i - 1].first == a[i].first && a[i].second != a[i - 1].second) flag = false;
		else if (a[i].second < a[i - 1].second) flag = false;
	if (a[q].first == b && a[q].second != n) flag = false;
	if (!flag) puts("unfair");
	else {
		q = unique(a + 1, a + q + 1) - (a + 1);
		if (a[q].second < n) a[++q] = pii(b, n); 
		S = b + 5 + q + 1, T = S + 1;
		for (int i = 1; i <= q; ++i) {		
			add(S, i, a[i].second - a[i - 1].second);
			for (int j = a[i - 1].first + 1; j <= a[i].first; ++j) 
				add(i, q + j, 1);
		}
		for (int i = 1; i <= b; ++i)
			add(q + i, q + b + 1 + i % 5, 1);
		for (int i = 1; i <= 5; ++i)
			add(q + b + i, T, n / 5);
		maxflow();
		if (flow == n) puts("fair");
		else puts("unfair");
	}
}