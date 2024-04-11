#include <bits/stdc++.h>
using namespace std;
typedef vector<int> VI;
typedef unsigned int ui;
const int maxn = 500000;
int u[maxn], v[maxn], w[maxn], cnt[maxn], dep[maxn], fa[maxn];
int getfa(int x) {
	if (fa[x] == x) return x;
	int p = getfa(fa[x]);
	dep[x] ^= dep[fa[x]];
	return fa[x] = p;
}
struct node {
	VI tree;
	int val;
	void build() {
		for (int& i : tree) {
			cnt[u[i]] = cnt[v[i]] = 1;
			dep[u[i]] = dep[v[i]] = 0;
			fa[u[i]] = u[i]; fa[v[i]] = v[i];
		}
		val = -1;
		VI ret;
		for (int& i : tree) {
			int U = u[i], V = v[i];
			int fu = getfa(U), fv = getfa(V);
			if (fu != fv) {
				if (cnt[fu] > cnt[fv]) swap(U, V), swap(fu, fv);
				if (dep[U] == dep[V]) dep[fu] ^= 1;
				cnt[fv] += cnt[fu];
				fa[fu] = fv;
				ret.push_back(i);
			}
			else if (dep[U] == dep[V]) {
				val = w[i];
				ret.push_back(i);
				break;
			}
		}
		tree = ret;
	}
} seg[maxn * 4];
int n, m, q, st, ed;
inline node merge(const node& lhs, const node& rhs) {
	node m;
	ui i = 0, j = 0;
	const VI &a = lhs.tree, &b = rhs.tree;
	for ( ; i < a.size() && j < b.size(); )
		if (w[a[i]] > w[b[j]]) m.tree.push_back(a[i++]);
		else m.tree.push_back(b[j++]);
	while (i < a.size()) m.tree.push_back(a[i++]);
	while (j < b.size()) m.tree.push_back(b[j++]);
	m.build();
	return m;
}
void build(int tot, int l, int r) {
	if (l == r) {
		seg[tot].val = -1;
		seg[tot].tree.push_back(l);
		return;	
	}
	int mid = (l + r) / 2;
	build(tot * 2, l, mid);
	build(tot * 2 + 1, mid + 1, r);
	seg[tot] = merge(seg[tot * 2], seg[tot * 2 + 1]);
}
node query(int tot, int l, int r) {
	if (st <= l && r <= ed) return seg[tot];
	int mid = (l + r) / 2;
	if (st <= mid && mid < ed) return merge(query(tot * 2, l, mid), query(tot * 2 + 1, mid + 1, r));
	else if (st <= mid) return query(tot * 2, l, mid);
	else return query(tot * 2 + 1, mid + 1, r);
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) 
		scanf("%d%d%d", &u[i], &v[i], w + i);
	build(1, 1, m);
	for (int i = 1; i <= q; ++i) {
		scanf("%d%d", &st, &ed);
		printf("%d\n", query(1, 1, m).val);
	}
}