#include <cstdio>
#include <set>

const int N = 200005;
const int S = 20000000;
const int K = 1000;
int n, q, a[N], t[S], left[S], right[S], size, root[N], from[N], l[N], r[N], x[N], type[N], qq[N];
bool ans[N];

void build(int v = 0, int tl = 0, int tr = n) {
	++size;
	if (tr - tl != 1) {
		int m = tl + tr >> 1;
		left[v] = v + 1;
		right[v] = v + (tr - tl & ~1);
		build(v + 1, tl, m);
		build(v + (tr - tl & ~1), m, tr);
	}
}

int update(int i, int v, int tl = 0, int tr = n) {
	left[size] = left[v];
	right[size] = right[v];
	t[size] = t[v];
	v = size++;
	if (tr - tl == 1) t[v] += 1;
	else {
		int m = tl + tr >> 1;
		if (i < m) left[v] = update(i, left[v], tl, m);
		else right[v] = update(i, right[v], m, tr);
		t[v] = t[left[v]] + t[right[v]];
	}
	return v;
}

int sq(int l, int r, int v, int tl = 0, int tr = n) {
	if (tl >= r || tr <= l) return 0;
	if (tl >= l && tr <= r) return t[v];
	int m = tl + tr >> 1;
	return sq(l, r, left[v], tl, m) + sq(l, r, right[v], m, tr);
}

int main() {
	scanf("%d%d", &n, &q);
	build();
	std::set<int> st;
	for (int i = 0; i < n; ++i) {
		st.insert(i);
		from[i] = ~(1 << 31);
	}
	for (int i = 0; i < q; ++i) {
		root[i + 1] = root[i];
		scanf("%d", type + i);
		if (type[i]) {
			scanf("%d", qq + i);
			--qq[i];
			if (!st.count(qq[i])) ans[i] = 1;
		} else {
			scanf("%d%d%d", l + i, r + i, x + i);
			--l[i];
			if (!x[i]) {
				std::set<int>::iterator it;
				while (it = st.lower_bound(l[i]), it != st.end() && *it < r[i]) {
					root[i + 1] = update(*it, root[i + 1]);
					st.erase(it);
				}
			}
		}
	}
	for (int i = 0; i < q; ++i) if (!type[i] && x[i]) {
		int ll = 1, rr = q + 1;
		while (ll < rr) {
			int m = ll + rr >> 1;
			if (sq(l[i], r[i], root[m]) == r[i] - l[i] - 1) rr = m;
			else ll = m + 1;
		}
		if (rr <= q) {
			int pos = *st.lower_bound(l[i]);
			from[pos] = std::min(from[pos], std::max(i + 1, rr));
		}
	}
	for (int i = 0; i < q; ++i) if (type[i]) {
		if (ans[i]) printf("NO\n");
		else if (from[qq[i]] <= i) printf("YES\n");
		else printf("N/A\n");
	}
	return 0;
}