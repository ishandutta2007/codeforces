#include <cstdio>
#include <algorithm>
#include <vector>

const int N = 200005;
const int Q = 1000000;
int n, q, inv[N], prev[N], a[N], next[N], ll[N], rr[N];
std::vector<std::pair<int, int> > all[N];
long long ans[Q];

struct query {
	int l, r, ind;
} qq[Q];

bool operator<(query a, query b) {
	return a.r < b.r;
}

bool cmp(std::pair<int, int> a, std::pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

struct tree {
	long long *t, *inc;
	tree() {
		t = new long long [N * 2];
		inc = new long long [N * 2];
	}
	void update(int l, int r, long long x, int v = 0, int tl = 0, int tr = n) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			t[v] += x * (tr - tl);
			inc[v] += x;
		} else {
			int m = tl + tr >> 1;
			update(l, r, x, v + 1, tl, m);
			update(l, r, x, v + (tr - tl & ~1), m, tr);
			t[v] = t[v + 1] + t[v + (tr - tl & ~1)] + inc[v] * (tr - tl);
		}
	}
	long long query(int l, int r, int v = 0, int tl = 0, int tr = n) {
		if (tl >= r || tr <= l) return 0;
		if (tl >= l && tr <= r) return t[v];
		int m = tl + tr >> 1;
		return query(l, r, v + 1, tl, m) + query(l, r, v + (tr - tl & ~1), m, tr) + inc[v] * (std::min(tr, r) - std::max(tl, l));
	}
} t0, t1;

int main() {
	scanf("%d%d", &n, &q);
	std::vector<int> vec;
	vec.push_back(-1);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		inv[a[i]] = i;
		while (vec.size() > 1 && a[i] > a[vec.back()]) vec.pop_back();
		prev[i] = vec.back();
		vec.push_back(i);
	}
	vec.clear();
	vec.push_back(n);
	for (int i = n - 1; i >= 0; --i) {
		while (vec.size() > 1 && a[i] > a[vec.back()]) vec.pop_back();
		next[i] = vec.back();
		vec.push_back(i);
	}
	std::vector<std::pair<int, std::pair<int, int> > > ev;
	for (int i = 1; i <= n; ++i) {
		std::vector<std::pair<int, int> > seg;
		ll[i] = prev[inv[i]] + 1, rr[i] = next[inv[i]] - 1;
		for (int j = 1; j * j < i; ++j) if (!(i % j)) {
			int l = inv[i / j], r = inv[j];
			if (l > r) std::swap(l, r);
			l = std::min(l, inv[i]);
			r = std::max(r, inv[i]);
			if (ll[i] <= l && rr[i] >= r && l != r) seg.push_back(std::make_pair(l, r));
		}
		if (!seg.empty()) {
			std::sort(seg.begin(), seg.end(), cmp);
			int amt = 0;
			for (int i = 0; i < (int)seg.size(); ++i) {
				while (amt && seg[i].second <= seg[amt - 1].second) --amt;
				seg[amt++] = seg[i];
			}
			seg.resize(amt);
			all[i] = seg;
			for (int j = 0; j < amt; ++j) ev.push_back(std::make_pair(seg[j].second + 1, std::make_pair(i, j)));
			ev.push_back(std::make_pair(rr[i] + 1, std::make_pair(i, amt)));
		}
	}
	std::sort(ev.begin(), ev.end());
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", &qq[i].l, &qq[i].r);
		--qq[i].l;
		qq[i].ind = i;
	}
	std::sort(qq, qq + q);
	for (int i = 1, j = 0, k = 0; i <= n; ++i) {
		for (; j < (int)ev.size() && ev[j].first == i; ++j) {
			int id = ev[j].second.first, ind = ev[j].second.second;
			if (ind) {
				t1.update(ll[id], all[id][ind - 1].first + 1, -1);
				t0.update(ll[id], all[id][ind - 1].first + 1, all[id][ind - 1].second);
				t0.update(ll[id], all[id][ind - 1].first + 1, i - all[id][ind - 1].second - 1 + (ind == all[id].size()));
			}
			if (ind != all[id].size()) {
				t1.update(ll[id], all[id][ind].first + 1, 1);
				t0.update(ll[id], all[id][ind].first + 1, -i + 1);
			}
		}
		for (; k < q && qq[k].r == i; ++k) ans[qq[k].ind] = t0.query(qq[k].l, i) + i * t1.query(qq[k].l, i);
	}
	for (int i = 0; i < q; ++i) printf("%lld\n", ans[i]);
	return 0;
}