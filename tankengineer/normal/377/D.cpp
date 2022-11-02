#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005, L = 300005;
vector<int> ins[N], del[N];

int n, l[N], v[N], r[N];

struct Max {
	int val, pos;

	Max() {
		val = 0;
		pos = -1;
	}

	Max(int val, int pos) : val(val), pos(pos) {}
};

inline bool operator < (const Max &a, const Max &b) {
	return a.val < b.val || a.val == b.val && a.pos < b.pos;
}

int tag[N << 1];
Max maxs[N << 1];

inline int getID(const int &l, const int &r) {
	return l + r | l != r;
}

inline Max max(const Max &a, const Max &b) {
	return a < b ? b : a;
}

inline void update(int l, int r) {
	int x = getID(l, r), m = l + r >> 1;
	maxs[x] = max(maxs[getID(l, m)], maxs[getID(m + 1, r)]);
	maxs[x].val += tag[x];
}

inline void pushdown(int l, int r) {
	int x = getID(l, r), m = l + r >> 1;
	if (tag[x]) {
		tag[getID(l, m)] += tag[x];
		maxs[getID(l, m)].val += tag[x];
		tag[getID(m + 1, r)] += tag[x];
		maxs[getID(m + 1, r)].val += tag[x];
		tag[x] = 0;
	}
}

void insert(int l, int r, int a, int b, int v) {
	if (a <= l && r <= b) {
		tag[getID(l, r)] += v;
		maxs[getID(l, r)].val += v;
	} else {
		pushdown(l, r);
		int m = l + r >> 1;
		if (a <= m) {
			insert(l, m, a, b, v);
		}
		if (b > m) {
			insert(m + 1, r, a, b, v);
		}
		update(l, r);
	}
}

Max query(int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		return maxs[getID(l, r)];
	} else {
		pushdown(l, r);
		int m = l + r >> 1;
		Max ret;
		if (a <= m) {
			ret = max(ret, query(l, m, a, b));
		}
		if (b > m) {
			ret = max(ret, query(m + 1, r, a, b));
		}
		return ret;
	}
}

void init(int l, int r) {
	tag[getID(l, r)] = 0;
	if (l == r) {
		maxs[getID(l, r)] = Max(0, l);
		return;
	}
	int m = l + r >> 1;
	init(l, m);
	init(m + 1, r);
	update(l, r);
}

struct Evt {
	int i, type, t;

	Evt(int i, int type) : i(i), type(type) {
		if (type == -1) {
			t = l[i];
		} else if (type == 0) {
			t = v[i];
		} else {
			t = r[i];
		}
	};
};

bool operator < (const Evt &a, const Evt &b) {
	return a.t < b.t || a.t == b.t && a.type < b.type;
}

int main() {
	scanf("%d", &n);
	vector<Evt> e;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d", l + i, v + i, r + i);
		for (int t = -1; t <= 1; ++t) {
			e.push_back(Evt(i, t));
		}
	}
	sort(e.begin(), e.end());
	int now_cnt = 0, last_met = -1;
	for (int i = 0; i < (int)e.size(); ++i) {
		int t = e[i].t, u = e[i].i, ty = e[i].type;
		if (ty == -1) {
			l[u] = now_cnt;	
		} else if (ty == 0) {
			v[u] = now_cnt;
			last_met = t;
			++now_cnt;
		} else if (ty == 1) {
			r[u] = now_cnt - 1;	
		}
	}
	vector<pair<int, int> > q;	
	for (int i = 0; i < n; ++i) {
		q.push_back(make_pair(v[i], i + 1));
		if (l[i]) {
			q.push_back(make_pair(l[i] - 1, -i));
		}
	}
	sort(q.begin(), q.end());
	int size = now_cnt;
	init(0, size);
	int ans = 0, ansl = 0, ansr = 0;
	for (int i = q.size() - 1; i >= 0; --i) {
		int j = i;
		while (j >= 0 && q[j].first == q[i].first) {
			if (q[j].second > 0) {
				int u = q[j].second - 1;
				insert(0, size, v[u], r[u], 1);
			} else {
				int u = -q[j].second;
				insert(0, size, v[u], r[u], -1);
			}
			--j;
		}
		Max tmp = query(0, size, q[i].first, size);	
		if (tmp.val > ans) {
			ans = tmp.val;
			ansl = q[i].first;
			ansr = tmp.pos;
		}
		i = j + 1;
	}
	vector<int> anst;
	for (int i = 0; i < n; ++i) {
		if (l[i] <= ansl && ansl <= v[i] && v[i] <= ansr && ansr <= r[i]) {
			anst.push_back(i + 1);
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < (int)anst.size(); ++i) {
		printf("%d%c", anst[i], " \n"[i == anst.size()]);
	}
	return 0;
}