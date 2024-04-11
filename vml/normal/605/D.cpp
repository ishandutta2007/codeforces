#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <ctime>
#include <map>
#define ld double
#define ll long long
#define mp make_pair

using namespace std;

const int maxn = (int)2e5 + 10;

struct pt {
	int a, b, c, d;

	pt() {

	}

	pt(int a, int b, int c, int d): a(a), b(b), c(c), d(d) {

	}
};

pt v[maxn];
set <pair <int, int> > t[4 * maxn];
int tr[4 * maxn];
int lnk[maxn];

queue <int> q;

void change(int it, int l, int r, int pos, int x, int posit) {
	if (l == r) {
		t[it].insert(make_pair(x, posit));
		tr[it] = min(tr[it], x);
	} else {
		int m = (l + r) / 2;

		if (pos <= m) {
			change(2 * it, l, m, pos, x, posit);
		} else {
			change(2 * it + 1, m + 1, r, pos, x, posit);
		}

		tr[it] = min(tr[2 * it], tr[2 * it + 1]);
	}
}

void go(int it, int l, int r, int lm, int rm, int x, int posit) {
	if (tr[it] > x) {
		return;
	}

	if (l == r) {
		while (!t[it].empty() && t[it].begin()->first <= x) {
			lnk[t[it].begin()->second] = posit;
			q.push(t[it].begin()->second);
			t[it].erase(t[it].begin());
		}

		if (t[it].empty()) {
			tr[it] = (int)1e9;
		} else {
			tr[it] = t[it].begin()->first;
		}
	} else if (l == lm && r == rm) {
		int m = (l + r) / 2;

		if (tr[2 * it] <= x) {
			go(2 * it, l, m, lm, m, x, posit);
		}

		if (tr[2 * it + 1] <= x) {
			go(2 * it + 1, m + 1, r, m + 1, rm, x, posit);
		}

		tr[it] = min(tr[2 * it], tr[2 * it + 1]);
	} else {
		int m = (l + r) / 2;

		if (rm <= m) {
			go(2 * it, l, m, lm, rm, x, posit);
		} else if (lm > m) {
			go(2 * it + 1, m + 1, r, lm, rm, x, posit);
		} else {
			go(2 * it, l, m, lm, m, x, posit);
			go(2 * it + 1, m + 1, r, m + 1, rm, x, posit);
		}

		tr[it] = min(tr[2 * it], tr[2 * it + 1]);
	}
}

int main() {
	for (int i = 0; i < 4 * maxn; i++) {
		tr[i] = (int)2e9;
	}

	int n;

	cin >> n;

	vector <int> a, b;

	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &v[i].a, &v[i].b, &v[i].c, &v[i].d);
		a.push_back(v[i].a);
		a.push_back(v[i].c);
		b.push_back(v[i].b);
		b.push_back(v[i].d);
	}

	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());

	if (a[0] != 0 || b[0] != 0) {
		cout << -1 << endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		v[i].a = lower_bound(a.begin(), a.end(), v[i].a) - a.begin();
		v[i].b = lower_bound(b.begin(), b.end(), v[i].b) - b.begin();
		v[i].c = lower_bound(a.begin(), a.end(), v[i].c) - a.begin();
		v[i].d = lower_bound(b.begin(), b.end(), v[i].d) - b.begin();
	}

	memset(lnk, -1, sizeof lnk);

	for (int i = 0; i < n; i++) {
		if (!(v[i].a == 0 && v[i].b == 0)) {
			change(1, 0, maxn - 1, v[i].a, v[i].b, i);
		} else {
			q.push(i);
			lnk[i] = -2;
		}
	}

	while (!q.empty()) {
		int pos = q.front();

		q.pop();

		go(1, 0, maxn - 1, 0, v[pos].c, v[pos].d, pos);
	}

	if (lnk[n - 1] == -1) {
		cout << -1 << endl;
		return 0;
	}

	vector <int> ans;

	int x = n - 1;

	while (lnk[x] != -2) {
		ans.push_back(x);
		x = lnk[x];
	}

	cout << (int)ans.size() + 1 << endl;

	cout << x + 1 << ' ';
	reverse(ans.begin(), ans.end());

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i] + 1);
	}

	return 0;
}