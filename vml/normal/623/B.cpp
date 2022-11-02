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

const int maxn = (int)1e6 + 10;

int v[maxn];
bool del[maxn];
vector <pair <int, ll> > pr;

void f(int x, ll a) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			pr.push_back(mp(i, a));

			while (x % i == 0) {
				x /= i;
			}
		}
	}

	if (x != 1) {
		pr.push_back(mp(x, a));
	}
}

ll sum[maxn];

ll go(int n, ll a, ll b) {
	pr.clear();

	f(v[0], 0);
	f(v[0] + 1, b);
	f(v[0] - 1, b);

	ll res = (ll)1e18;

	for (int j = 0; j < (int)pr.size(); j++) {
		memset(del, 0, sizeof del);
		int x = pr[j].first;

		int l = n;
		int r = - 1;

		for (int i = 1; i < n; i++) {
			int y = v[i] % x;

			if (y != 0 && y != 1 && y != x - 1) {
				l = min(l, i);
				r = max(r, i);
			}

			if (y == 1 || y == x - 1) {
				del[i] = true;
			}
		}

		if (l != n) {
			ll sum = 0;
			for (int i = l - 1; i >= 1; i--) {
				if (del[i]) {
					sum += b;
				}

				if (sum >= a * (l - i)) {
					sum = 0;
					l = i;
				}
			}

			sum = 0;

			for (int i = r + 1; i < n; i++) {
				if (del[i]) {
					sum += b;
				}

				if (sum >= a * (i - r)) {
					sum = 0;
					r = i;
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				sum[i] = a;
				if (del[i]) {
					sum[i] -= b;
				}
			}

			ll mins = 0;
			l = -1;

			ll now = 0;
			int lm = 1;

			for (int i = 1; i < n; i++) {
				now += sum[i];

				if (now >= 0) {
					now = 0;
					lm = i + 1;
				}

				if (mins > now) {
					mins = now;
					l = lm;
					r = i;
				}
			}
		}

		ll ans = a * (r - l + 1);

		if (l == -1) {
			ans = 0;
		}

		for (int i = 0; i < l; i++) {
			if (del[i]) {
				ans += b;
			}
		}

		for (int i = r + 1; i < n; i++) {
			if (del[i]) {
				ans += b;
			}
		}

		res = min(res, ans + pr[j].second);
	}

	return res;
}

int main() {
	int n;

	scanf("%d", &n);
	ll a, b;

	cin >> a >> b;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	ll ans = go(n, a, b);

	reverse(v, v + n);

	ans = min(ans, go(n, a, b));

	cout << ans << endl;

	return 0;
}