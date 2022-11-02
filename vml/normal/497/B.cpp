#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int maxn = (int)1e5 + 10;

int v[maxn];
int f[maxn];
int s[maxn];
int n;

int go_sum(int l, int r) {
	if (l == 0) {
		return max(f[r], s[r]);
	}

	return max(f[r] - f[l - 1], s[r] - s[l - 1]);
}

pair <int, int> check(int pos, int cnt) {
	if (pos == n) {
		return make_pair(0, 0);
	}

	int l = pos;
	int r = n - 1;

	while (l != r) {
		int m = (l + r) / 2;

		if (go_sum(pos, m) < cnt) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	if (go_sum(pos, l) < cnt) {
		return make_pair(-1, -1);
	}

	pair <int, int> t = check(l + 1, cnt);

	if (t.first == -1) {
		return t;
	}

	if (f[l] - f[pos - 1] == cnt) {
		if (s[l] - s[pos - 1] == cnt) {
			throw 1;
		}
		t.first++;
	} else if (s[l] - s[pos - 1] == cnt) {
		t.second++;
	} else {
		throw 1;
	}

	return t;
}

bool go(int cnt, bool st) {
	int l = 0;
	int r = n - 1;

	while (l != r) {
		int m = (l + r + 1) / 2;

		if (go_sum(m, n - 1) < cnt) {
			r = m - 1;
		} else {
			l = m;
		}
	}

	int t1, t2;

	if (l == 0) {
		t1 = f[n - 1];
		t2 = s[n - 1];
	} else {
		t1 = f[n - 1] - f[l - 1];
		t2 = s[n - 1] - s[l - 1];
	}

	return (!((t1 > t2) ^ (st)));
}

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	f[0] = 0;
	s[0] = 0;

	if (v[0] == 1) {
		f[0]++;
	} else {
		s[0]++;
	}

	for (int i = 1; i < n; i++) {
		f[i] = f[i - 1];
		s[i] = s[i - 1];

		if (v[i] == 1) {
			f[i]++;
		} else {
			s[i]++;
		}
	}

	int x = 0, y = 0;

	vector <pair <int, int> > res;

	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			x++;
			if (x > y) {
				pair <int, int> ans = check(i + 1, x);

				if (ans.first != -1) {
					ans.first++;
					if (ans.first != ans.second) {
						if (go(x, ans.first > ans.second)) {
							res.push_back(make_pair(x, max(ans.first, ans.second)));
						}
					}
				}
			}
		} else {
			y++;
			if (y > x) {
				pair <int, int> ans = check(i + 1, y);

				if (ans.first != -1) {
					ans.second++;
					if (ans.first != ans.second) {
						if (go(y, ans.first > ans.second)) {
							res.push_back(make_pair(y, max(ans.first, ans.second)));
						}
					}
				}
			}
		}
	}

	printf("%d\n", (int)res.size());

	for (int i = 0; i < (int)res.size(); i++) {
		swap(res[i].first, res[i].second);
	}

	sort(res.begin(), res.end());

	for (int i = 0; i < (int)res.size(); i++) {
		printf("%d %d\n", res[i].first, res[i].second);
	}

	return 0;
}