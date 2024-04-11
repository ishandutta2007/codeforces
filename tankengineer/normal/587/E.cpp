#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Bases {
	vector<unsigned int> b;

	bool add(unsigned num) {
		for (int i = b.size() - 1; i >= 0; --i) {
			num = min(num, num ^ b[i]);
		}
		if (num) {
			b.insert(lower_bound(b.begin(), b.end(), num), num);
			return true;
		}
		return false;
	}

	int getAns() {
		int r = b.size();
		if (b.size() && b[0] == 1) {
			--r;
		}
		return r;
	}
};

const int N = 200005 << 1;

int tag[N];

vector<int> as[N];

int n, q;

int a[N];

Bases cur;

inline int getID(int l, int r) {
	return l + r | l != r;
}

void covern(int l, int r, int a) {
	int x = getID(l, r);
	tag[x] ^= a;
	for (int j = 0; j < (int)as[x].size(); ++j) {
		as[x][j] ^= a;
	}
}

void pushdown(int l, int r) {
	int x = getID(l, r);
	if (tag[x]) {
		int m = l + r >> 1;
		covern(l, m, tag[x]);
		covern(m + 1, r, tag[x]);
		tag[x] = 0;	
	}
}

void update(int l, int r) {
	int x = getID(l, r), m = l + r >> 1, lc = getID(l, m), rc = getID(m + 1, r);
	Bases tmp;
	as[x].clear();
	for (int i = 0; i < (int)as[lc].size(); ++i) {
		if (tmp.add(as[lc][i])) {
			as[x].push_back(as[lc][i]);
		}
	}
	for (int i = 0; i < (int)as[rc].size(); ++i) {
		if (tmp.add(as[rc][i])) {
			as[x].push_back(as[rc][i]);
		}
	}
}

void init(int l, int r) {
	int x = getID(l, r);	
	if (l == r) {
		as[x].push_back(a[l]);
		return;
	}
	int m = l + r >> 1;
	init(l, m), init(m + 1, r);
	update(l, r);
}

void cover(int l, int r, int a, int b, int v) {
	if (a <= l && r <= b) {
		covern(l, r, v);
		return;
	}
	pushdown(l, r);
	int m = l + r >> 1;
	if (a <= m) {
		cover(l, m, a, b, v);
	}
	if (b > m) {
		cover(m + 1, r, a, b, v);
	}
	update(l, r);
}

void query(int l, int r, int a, int b) {
	if (a <= l && r <= b) {
		int x = getID(l, r);
		for (int i = 0; i < (int)as[x].size(); ++i) {
			cur.add(as[x][i]);
		}
		return;
	}
	pushdown(l, r);
	int m = l + r >> 1;
	if (a <= m) {
		query(l, m, a, b);
	}
	if (b > m) {
		query(m + 1, r, a, b);
	}
	update(l, r);
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i] = a[i] << 1 | 1;
	}
	init(0, n - 1);
	while (q--) {
		int t, l, r, x;
		scanf("%d%d%d", &t, &l, &r);
		--l, --r;
		if (t == 1) {
			scanf("%d", &x);
			x <<= 1;
			cover(0, n - 1, l, r, x);
		} else {
			cur.b.clear();
			cur.b.push_back(1);
			query(0, n - 1, l, r);
			cout << (1ll << cur.getAns()) << endl;
		}
	}
	return 0;
}