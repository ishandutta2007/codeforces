#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cassert>
#include <set>

#define mp make_pair

using namespace std;

const int MAXN = 1e5;

int a[MAXN], t[MAXN], x[MAXN];
int d[4 * MAXN];

void update(int i, int l, int r, int pos, int f) {
	if (l > pos || r < pos)
		return;
	if (l == r) {
		d[i] = f;
		return;
	}
	int m = (l + r) / 2;
	update(2 * i, l, m, pos, f);
	update(2 * i + 1, m + 1, r, pos, f);
	d[i] = d[2 * i] + d[2 * i + 1];
}
void update(int pos, int f) { update(1, 0, MAXN - 1, pos, f); }

int get(int i, int l, int r, int ql, int qr) {
	if (l > r || ql > r || l > qr || ql > ql)
		return 0;
	if (ql <= l && r <= qr)
		return d[i];
	int m = (l + r) / 2;
	return get(2 * i, l, m, ql, qr) + get(2 * i + 1, m + 1, r, ql, qr);
}
int get(int ql, int qr) { return get(1, 0, MAXN - 1, ql, qr); }

struct El {
	int x, t, a, num;
	El(int x = 0, int t = 0, int a = 0, int num = 0):
		x(x), t(t), a(a), num(num) {}
};
bool operator <(El a, El b) { return mp(mp(a.x, a.t), mp(a.a, a.num)) < mp(mp(b.x, b.t), mp(b.a, b.num)); }

vector <El> v;
int k[MAXN];
int beg[MAXN], en[MAXN];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", a + i, t + i, x + i);
		v.push_back(El(x[i], t[i], a[i], i));
	}
	
	sort(v.begin(), v.end());
	beg[0] = 0;
	for (int i = 1; i < int(v.size()); i++) {
		if (v[i].x != v[i - 1].x)
			beg[i] = i;
		else
			beg[i] = beg[i - 1];
	}
	en[int(v.size()) - 1] = int(v.size()) - 1;
	for (int i = int(v.size()) - 2; i >= 0; i--) {
		if (v[i].x != v[i + 1].x)
			en[i] = i;
		else
			en[i] = en[i + 1];
	}
	for (int i = 0; i < int(v.size()); i++)
		k[v[i].num] = i;
	
	for (int i = 0; i < 4 * MAXN; i++)
		d[i] = 0;
	
	for (int t = 0; t < n; t++) {
		int p = k[t];
		if (a[t] == 1)
			update(p, 1);
		else if (a[t] == 2)
			update(p, -1);
		else if (a[t] == 3)
			printf("%d\n", get(beg[p], p));
	}
	
	return 0;
}