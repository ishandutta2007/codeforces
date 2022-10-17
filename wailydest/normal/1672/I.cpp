#include <cstdio>
#include <set>
#include <vector>

const int INF = ~(1 << 31) >> 6;

const int N = 500000;
int n, p[N], inv[N];

struct tree {
	std::vector<int> add;
	std::vector<std::pair<int, int> > t;
	void build(int v = 0, int tl = 0, int tr = n) {
		if (tr - tl == 1) t[v] = std::make_pair(-INF, tl);
		else {
			int m = tl + tr >> 1;
			build(v + 1, tl, m);
			build(v + (tr - tl & ~1), m, tr);
			t[v] = std::max(t[v + 1], t[v + (tr - tl & ~1)]);
		}
	}
	tree() {
		t.resize(2 * N);
		add.resize(2 * N);
	}
	void update(int l, int r, int x, int v = 0, int tl = 0, int tr = n) {
		if (tl >= r || tr <= l) return;
		if (tl >= l && tr <= r) {
			t[v].first += x;
			add[v] += x;
		} else {
			int m = tl + tr >> 1;
			update(l, r, x, v + 1, tl, m);
			update(l, r, x, v + (tr - tl & ~1), m, tr);
			t[v] = std::max(t[v + 1], t[v + (tr - tl & ~1)]);
			t[v].first += add[v];
		}
	}
	int query(int l, int r, int v = 0, int tl = 0, int tr = n) {
		if (tl >= r || tr <= l) return -INF * 10;
		if (tl >= l && tr <= r) return t[v].first;
		int m = tl + tr >> 1;
		return std::max(query(l, r, v + 1, tl, m), query(l, r, v + (tr - tl & ~1), m, tr)) + add[v];
	}
} t[2];

struct rmq {
	std::vector<int> t;
	rmq() {
		t.resize(2 * N, -INF);
	}
	void build() {
		for (int i = n - 1; i; --i) t[i] = std::max(t[i << 1], t[i << 1 | 1]);
	}
	void set(int i, int x) {
		for (i += n, t[i] = x; i; i >>= 1) t[i >> 1] = std::max(t[i], t[i ^ 1]);
	}
	int query(int l, int r) {
		int mx = -INF * 10;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) mx = std::max(mx, t[l++]);
			if (r & 1) mx = std::max(mx, t[--r]);
		}
		return mx;
	}
} tmx[2];

struct bit {
	std::vector<int> b;
	bit() {
		b.resize(N);
	}
	void add(int i, int d) {
		while (i < n) {
			b[i] += d;
			i |= i + 1;
		}
	}
	int get(int i) {
		int s = 0;
		while (i >= 0) {
			s += b[i];
			i = (i & i + 1) - 1;
		}
		return s;
	}
} dind, dval;

std::set<int> ind0, val0, ind1, val1;
void update0(int l, int r, int bound) {
	int mx;
	while (mx = tmx[0].query(l, r), mx >= bound) {
		ind0.insert(inv[mx]);
		val0.insert(mx);
		tmx[0].set(inv[mx], -INF);
		r = inv[mx];
		t[0].update(inv[mx], inv[mx] + 1, -t[0].query(inv[mx], inv[mx] + 1) + mx - inv[mx] + dval.get(mx) - dind.get(inv[mx]));
	}
}

void update1(int l, int r, int bound) {
	int mx;
	while (mx = tmx[1].query(l, r), -mx <= bound) {
		mx = -mx;
		ind1.insert(inv[mx]);
		val1.insert(mx);
		tmx[1].set(inv[mx], -INF);
		l = inv[mx] + 1;
		t[1].update(inv[mx], inv[mx] + 1, -t[1].query(inv[mx], inv[mx] + 1) + inv[mx] - mx + dind.get(inv[mx]) - dval.get(mx));
	}
}

int main() {
	scanf("%d", &n);
	t[0].build();
	t[1].build();
	for (int i = 0; i < n; ++i) {
		scanf("%d", p + i);
		--p[i];
		inv[p[i]] = i;
		if (i < p[i]) tmx[1].t[n + i] = -p[i];
		else tmx[0].t[n + i] = p[i];
	}
	tmx[0].build();
	tmx[1].build();
	update0(0, n, 0);
	update1(0, n, n);
	int ans, rmn = n;
	for (ans = 0; rmn;) {
		if (t[0].t.front().first + ans >= 0) {
			--rmn;
			int id = t[0].t.front().second;
			t[0].update(id, id + 1, -INF);
			std::set<int>::iterator it = val1.lower_bound(p[id]);
			if (it != val1.end() && inv[*it] < id) {
				int fi = inv[*it];
				it = ind1.upper_bound(id);
				t[1].update(fi, it == ind1.end() ? n : *it, 1);
			}
			dind.add(id, -1);
			dval.add(p[id], -1);
			val0.erase(p[id]);
			ind0.erase(id);
			it = ind0.lower_bound(id);
			int l, r;
			if (it == ind0.end()) r = n;
			else r = *it;
			if (it == ind0.begin()) l = 0;
			else l = *prev(it) + 1;
			update0(l, r, it == ind0.begin() ? 0 : p[*prev(it)] + 1);
		} else if (t[1].t.front().first + ans >= 0) {
			--rmn;
			int id = t[1].t.front().second;
			t[1].update(id, id + 1, -INF);
			std::set<int>::iterator it = ind0.lower_bound(id);
			if (it != ind0.end() && p[id] > p[*it]) {
				int fi = *it;
				it = val0.lower_bound(p[id]);
				t[0].update(fi, it == val0.end() ? n : inv[*it], 1);
			}
			dind.add(id, -1);
			dval.add(p[id], -1);
			val1.erase(p[id]);
			ind1.erase(id);
			it = ind1.lower_bound(id);
			int l, r;
			if (it == ind1.end()) r = n;
			else r = *it;
			if (it == ind1.begin()) l = 0;
			else l = *prev(it) + 1;
			update1(l, r, it == ind1.end() ? n : p[*it] - 1);
		} else ++ans;
	}
	printf("%d\n", ans);
	return 0;
}