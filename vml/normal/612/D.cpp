#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <set>
#include <cstring>
#include <ctime>
#include <map>
#include <bitset>
#define ld double
#define ll long long
#define mp make_pair
#define pii pair <int, int>
#define forn(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;

const int maxn = (int)1e6 + 10;
pair <int, int> v[maxn];

struct point {
	int x;
	int y;
	int sz;
	int l, r;

	point(): x(0), y(0), sz(0), l(-1), r(-1) {

	}

	point(int x, int y, int sz, int l, int r): x(x), y(y), sz(sz), l(l), r(r) {

	}
};

int my_rand() {
	return rand() * RAND_MAX + rand();
}

point mas[maxn];
int position = 0;

int my_new(int x, int y, int sz, int l, int r) {
	mas[position] = point(x, y, sz, l, r);

	return position++;
}

int size(int t) {
	if (t == -1) {
		return 0;
	}

	return mas[t].sz;
}

void recalc(int t) {
	mas[t].sz = size(mas[t].l) + size(mas[t].r) + 1;
}

void split_sz(int t, int cnt, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	} else if (size(mas[t].l) >= cnt) {
		split_sz(mas[t].l, cnt, l, mas[t].l);
		recalc(t);
		r = t;
	} else {
		split_sz(mas[t].r, cnt - size(mas[t].l) - 1, mas[t].r, r);
		recalc(t);
		l = t;
	}
}

int merge(int l, int r) {
	if (l == -1) {
		return r;
	} else if (r == -1) {
		return l;
	} else if (mas[l].y > mas[r].y) {
		mas[l].r = merge(mas[l].r, r);
		recalc(l);
		return l;
	} else {
		mas[r].l = merge(l, mas[r].l);
		recalc(r);
		return r;
	}
}

void split(int t, int x, int &l, int &r) {
	if (t == -1) {
		l = -1;
		r = -1;
	} else if (mas[t].x > x) {
		split(mas[t].l, x, l, mas[t].l);
		r = t;
		recalc(r);
	} else {
		split(mas[t].r, x, mas[t].r, r);
		l = t;
		recalc(l);
	}
}

int insert(int t, int x) {
	int l, r;

	split(t, x, l, r);

	return merge(merge(l, my_new(x, my_rand(), 1, -1, -1)), r);
}

int kth(int &t, int cnt) {
	int l, m, r;

	split_sz(t, cnt, l, r);

	split_sz(l, cnt - 1, l, m);

	int ans = mas[m].x;

	t = merge(merge(l, m), r);

	return ans;
}

int erase(int t) {
	int l, r;

	split_sz(t, 1, l, r);

	return r;
}

int mins(int t) {
	if (mas[t].l != -1) {
		return mins(mas[t].l);
	}

	return mas[t].x;
}

int main() {
	int k, n;

	cin >> n >> k;

	forn(i, n) {
		scanf("%d %d", &v[i].first, &v[i].second);
	}

	sort(v, v + n);

	int t = -1;

	vector <pair <int, int> > ans;

	for (int i = 0; i < n; i++) {
		while (t != -1 && mins(t) < v[i].first) {
			t = erase(t);
		}

		t = insert(t, v[i].second);

		if (size(t) >= k) {
			int r = kth(t, size(t) - k + 1);

			if (ans.empty() || ans.back().second < v[i].first) {
				ans.push_back(make_pair(v[i].first, r));
			} else {
				ans.back().second = r;
			}
		}
	}

	cout << ans.size() << endl;

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d %d\n", ans[i].first, ans[i].second);
	}

	return 0;
}