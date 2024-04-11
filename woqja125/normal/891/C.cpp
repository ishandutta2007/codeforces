#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

struct UF {
	int p[500001], l[500001];
	int m[1000001];
	int t = -1;
	UF(int n) {
		for (int i = 1; i <= n; i++) p[i] = i, l[i] = 0;
	}
	int R(int x) {
		if (p[x] == x) return x;
		else return R(p[x]);
	}
	void commit() {
		t = -1;
	}
	void revert() {
		while (t >= 0) {
			int v = m[t--];
			if (v > 0) p[v] = v;
			else l[-v]--;
		}
	}
	bool uni(int x, int y) {
		x = R(x);
		y = R(y);
		if (x == y) return false;
		if (l[x] > l[y]) swap(x, y);
		m[++t] = x;
		p[x] = y;
		if (l[x] == l[y]) {
			l[y]++;
			m[++t] = -y;
		}
		return true;
	}
};

bool ans[500001];

struct E {
	int x, y, w;
	bool operator<(const E &A) const {
		return w < A.w;
	}
} ed[500001], ed2[500001];

struct en {
	int i;
	bool operator<(const en &A) const {
		return ed[i].w < ed[A.i].w;
	}
} query[500001];

struct query_seg {
	int w, o;
	vector<int> e;
	bool operator<(const query_seg &t) const {
		return w < t.w;
	}
};

struct qs_ptr {
	query_seg *s;
	bool operator<(const qs_ptr &t) const {
		return *s < *(t.s);
	}
	qs_ptr(query_seg *p) {
		s = p;
	}
};

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	UF *u = new UF(n);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &ed[i].x, &ed[i].y, &ed[i].w), ed2[i] = ed[i];
	sort(ed2 + 1, ed2 + m + 1);

	int q, k, t;
	scanf("%d", &q);
	vector<qs_ptr> qsv;
	for (int i = 1; i <= q; i++) {
		scanf("%d", &k);
		for (int j = 1; j <= k; j++) {
			scanf("%d", query+j);
		}
		sort(query + 1, query + k + 1);
		for (int j = 1, t; j <= k; j = t) {
			query_seg *tmp = new query_seg();
			tmp->o = i;
			tmp->w = ed[query[j].i].w;
			for (t = j; t<=k && tmp->w == ed[query[t].i].w; t++) {
				tmp->e.push_back(query[t].i);
			}
			qsv.emplace_back(tmp);
		}
		ans[i] = true;
	}

	sort(qsv.begin(), qsv.end());
	t = 0;
	for (int i = 1, j; i <= m; i=j) {
		for (; t < qsv.size() && ed2[i].w == qsv[t].s->w; t++) {
			for (auto &e : qsv[t].s->e) {
				if (!u->uni(ed[e].x, ed[e].y)) {
					ans[qsv[t].s->o] = false;
				}
			}
			u->revert();
		}
		for (j = i; j<=m && ed2[i].w == ed2[j].w; j++) u->uni(ed2[j].x, ed2[j].y);
		u->commit();
	}
	for (int i = 1; i <= q; i++) printf(ans[i] ? "YES\n" : "NO\n");
	return 0;
}