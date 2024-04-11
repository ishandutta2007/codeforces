#include <cstdio>
#include <algorithm>
#include <vector>

const int INF = 1070000000;

const int N = 200000;
int n, pr[N], wup[N], in[N], ord[N], top[N], size[N];
bool from[N], status[N], ans[N];
std::vector<std::pair<int, int> > g[N];

void dfs0(int v) {
	for (int i = 0; i < (int)g[v].size(); ++i) if (g[v][i].first == pr[v]) 
		g[v].erase(g[v].begin() + i);
	size[v] = 1;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		pr[g[v][i].first] = v;
		wup[g[v][i].first] = g[v][i].second;
		dfs0(g[v][i].first);
		size[v] += size[g[v][i].first];
		if (size[g[v][i].first] > size[g[v][0].first]) std::swap(g[v][i], g[v][0]);
	}
}

void dfs1(int v) {
	static int dt = 0;
	ord[dt] = v;
	in[v] = dt++;
	for (int i = 0; i < (int)g[v].size(); ++i) {
		if (i) top[g[v][i].first] = g[v][i].first;
		else top[g[v][i].first] = top[v];
		dfs1(g[v][i].first);
	}
}

struct item {
	int mx[2];
	long long sum[2];
	bool upd;
	void push(int v, int tl, int tr);
} t[N << 1];

item operator+(item a, item b) {
	item res;
	res.upd = 0;
	res.mx[0] = std::max(a.mx[0], b.mx[0]);
	res.mx[1] = std::max(a.mx[1], b.mx[1]);
	res.sum[0] = a.sum[0] + b.sum[0];
	res.sum[1] = a.sum[1] + b.sum[1];
	return res;
}

void build(int v = 0, int tl = 0, int tr = n) {
	if (tr - tl == 1) {
		t[v].sum[0] = wup[ord[tl]];
		t[v].sum[1] = 0;
		t[v].upd = 0;
		t[v].mx[0] = t[v].mx[1] = -INF;
		if (top[ord[tl]] != ord[tl]) t[v].mx[0] = 0;
	} else {
		int m = tl + tr >> 1;
		build(v + 1, tl, m);
		build(v + (tr - tl & ~1), m, tr);
		t[v] = t[v + 1] + t[v + (tr - tl & ~1)];
	}
}

void item::push(int v, int tl, int tr) {
	if (upd) {
		std::swap(mx[0], mx[1]);
		std::swap(sum[0], sum[1]);
		++mx[1];
		--mx[0];
		if (tr - tl > 1) {
			t[v + 1].upd ^= 1;
			t[v + (tr - tl & ~1)].upd ^= 1;
		}
		upd = 0;
	}
}

void change(int i, int d, int v = 0, int tl = 0, int tr = n) {
	t[v].push(v, tl, tr);
	if (tr - tl == 1) {
		t[v].mx[(bool)t[v].sum[1]] += d;
	} else {
		int m = tl + tr >> 1;
		if (i < m) {
			change(i, d, v + 1, tl, m);
			t[v + (tr - tl & ~1)].push(v + (tr - tl & ~1), m, tr);
		} else {
			change(i, d, v + (tr - tl & ~1), m, tr);
			t[v + 1].push(v + 1, tl, m);
		}
		t[v] = t[v + 1] + t[v + (tr - tl & ~1)];
	}
}

void update(int l, int r, int v = 0, int tl = 0, int tr = n) {
	t[v].push(v, tl, tr);
	if (!(tl >= r || tr <= l)) {
		if (tl >= l && tr <= r) {
			t[v].upd = 1;
			t[v].push(v, tl, tr);
		} else {
			int m = tl + tr >> 1;
			update(l, r, v + 1, tl, m);
			update(l, r, v + (tr - tl & ~1), m, tr);
			t[v] = t[v + 1] + t[v + (tr - tl & ~1)];
		}
	}
}

void calc(int v = 0, int tl = 0, int tr = n) {
	t[v].push(v, tl, tr);
	if (tr - tl == 1) {
		if (tl) ans[wup[ord[tl]]] = (bool)t[v].sum[1];
	} else {
		int m = tl + tr >> 1;
		calc(v + 1, tl, m);
		calc(v + (tr - tl & ~1), m, tr);
	}
};

bool par = 1;

bool test() {
	return !par && std::max(t[0].mx[0], t[0].mx[1]) <= 1;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		g[a].push_back(std::make_pair(b, i));
		g[b].push_back(std::make_pair(a, i));
	}
	dfs0(0);
	dfs1(0);
	build();
	int type;
	while (scanf("%d", &type), type != 3) {
		if (type == 1) {
			int v;
			scanf("%d", &v);
			--v;
			par = !par;
			while (true) {
				update(in[top[v]], in[v] + 1);
				v = top[v];
				status[v] = !status[v];
				if (!v) break;
				change(in[pr[v]] + 1, status[v] ? 1 : -1);
				v = pr[v];
			}
			if (test()) printf("%lld\n", t[0].sum[1]);
			else printf("0\n");
		} else {
			if (test()) {
				calc();
				int amt = 0;
				for (int i = 1; i < n; ++i) amt += ans[i];
				printf("%d ", amt);
				for (int i = 1; i < n; ++i) if (ans[i]) printf("%d ", i);
				printf("\n");
			} else printf("0\n");
		}
		fflush(stdout);
	}
	return 0;
}