#include <cstdio>
#include <algorithm>

const int N = 200000;
int t, n, m, q, top1[N], ll[N], rr[N], a[N], b[N], l[N], r[N], left[N], right[N];
std::pair<int, int> qq[N];

int find1(int v) {
	if (top1[v] == -1) return v;
	return top1[v] = find1(top1[v]);
}

int find2(int v) {
	if (left[v] == v) return v;
	return left[v] = find2(left[v]);
}

void merge1(int u, int v) {
	u = find1(u);
	v = find1(v);
	if (u != v) top1[u] = v;
}

void merge2(int u, int v) {
	u = find2(u);
	v = find2(v);
	if (u != v) {
		if (u > v) std::swap(u, v);
		left[v] = u;
		right[u] = right[v];
	}
}

void go(int x) {
	x = find2(x);
	while (x && find1(x - 1) == find1(x)) {
		merge2(x, x - 1);
		x = find2(x);
	}
	while (right[x] + 1 < n && find1(right[x] + 1) == find1(x)) merge2(x, right[x] + 1);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &q);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", a + i, b + i);
			--a[i];
			--b[i];
		}
		for (int i = 0; i < q; ++i) {
			scanf("%d%d", l + i, r + i);
			--l[i];
			--r[i];
			ll[i] = 0;
			rr[i] = m;
			qq[i] = std::make_pair(m / 2, i);
		}
		bool any;
		do {
			any = 0;
			std::sort(qq, qq + q);
			for (int i = 0; i < n; ++i) {
				top1[i] = -1;
				left[i] = right[i] = i;
			}
			for (int i = 0, j = 0; i < q; ++i) {
				while (j < qq[i].first) {
					merge1(a[j], b[j]);
					++j;
				}
				int id = qq[i].second;
				if (ll[id] < rr[id]) {
					go(l[id]);
					go(r[id]);
					if (find2(l[id]) == find2(r[id])) rr[id] = qq[i].first;
					else ll[id] = qq[i].first + 1;
					qq[i].first = ll[id] + rr[id] >> 1;
					any = 1;
				}
			}
		} while (any);
		for (int i = 0; i < q; ++i) printf("%d ", rr[i]);
		printf("\n");
	}
	return 0;
}