#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <memory.h>
#define mp make_pair
#define pii pair<int, int>
#define ll long long
#define ui unsigned int
#define ld double

using namespace std;

const int maxn = (int)2e5 + 10;
const ld eps = 1e-10;

ll v[maxn];
ll sum[maxn];

ll go_sum(int l, int r) {
	if (l > r) {
		return 0;
	}

	if (l == 0) {
		return sum[r];
	}

	return sum[r] - sum[l - 1];
}

int main() {
	int n;

	cin >> n;

	for (int i = 0; i < n; i++) {
		scanf("%I64d", &v[i]);
	}

	sort(v, v + n);

	ll now = 0;

	for (int i = 0; i < n; i++) {
		now += v[i];
		sum[i] = now;
	}

	long double res = -1.0;
	int lnk;
	int cnt;
	bool st;

	for (int i = 0; i < n; i++) {
		int l = 0;
		int r = min(i, n - i - 1);

		while (l != r) {
			int m1 = (l + r) / 2;
			int m2 = (l + r) / 2 + 1;

			ll summ = go_sum(i - m1, i - 1) + go_sum(n - m1, n - 1) + v[i];

			ll x = v[i - m2] + v[n - m2];

			if (x * (2 * m1 + 1) < 2 * summ) {
				r = m1;
			} else {
				l = m2;
			}
		}

		ll summ = go_sum(i - l, i - 1) + go_sum(n - l, n - 1) + v[i];
		ll cntt = 2 * l + 1;

		if (res * cntt < summ - v[i] * cntt) {
			res = (ld)summ / cntt - v[i];
			lnk = i;
			cnt = l;
			st = false;
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int l = 0;
		int r = min(i, n - i - 2);

		while (l != r) {
			int m1 = (l + r) / 2;
			int m2 = (l + r) / 2 + 1;

			ll summ = go_sum(i - m1, i - 1) + go_sum(n - m1, n - 1) + v[i] + v[i + 1];

			ll x = v[i - m2] + v[n - m2];

			if (x * (2 * m1 + 2) < 2 * summ) {
				r = m1;
			} else {
				l = m2;
			}
		}

		ll summ = go_sum(i - l, i - 1) + go_sum(n - l, n - 1) + v[i] + v[i + 1];
		ll cntt = 2 * l + 2;

		if (res + eps < (ld)summ / cntt - (v[i] + v[i + 1]) / 2.0) {
			res = (ld)summ / cntt - (v[i] + v[i + 1]) / 2.0;
			lnk = i;
			cnt = l;
			st = true;
		}
	}

	cout << cnt * 2 + 1 + st << endl;

	vector <ll> ans;

	ans.push_back(v[lnk]);

	if (st) {
		ans.push_back(v[lnk + 1]);
	}

	for (int i = n - 1; i >= n - cnt; i--) {
		ans.push_back(v[i]);
	}

	for (int i = lnk - 1; i >= lnk - cnt; i--) {
		ans.push_back(v[i]);
	}

	for (int i = 0; i < (int)ans.size(); i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}