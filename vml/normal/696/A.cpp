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

#define ll long long
#define ld double
#define pii pair <int, int>
#define pll pair <ll, ll>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
#define mp make_pair

using namespace std;

vector <ll> v;

int main() {
	ll x = 1;

	while (x <= (ll)1e18) {
		v.push_back(x);
		x *= 2;
	}

	int q;

	scanf("%d", &q);

	map <pll, ll> dp;

	while (q--) {
		ll x, y, w;
		int tp;

		scanf("%d %I64d %I64d", &tp, &x, &y);

		int hx = upper_bound(v.begin(), v.end(), x) - v.begin() - 1;
		int hy = upper_bound(v.begin(), v.end(), y) - v.begin() - 1;

		if (tp == 1) {
			scanf("%I64d", &w);
			while (x != y) {
				if (hx > hy) {
					hx--;
					dp[mp(x, x / 2)] += w;
					x /= 2;
				} else {
					hy--;
					dp[mp(y, y / 2)] += w;
					y /= 2;
				}
			}
		} else {
			ll ans = 0;

            int cnt = 0;
			while (x != y) {
				if (hx > hy) {
					hx--;
					ans += dp[mp(x, x / 2)];
					x /= 2;
				} else {
					hy--;
					ans += dp[mp(y, y / 2)];
					y /= 2;
				}
			}

			printf("%I64d\n", ans);
		}
	}

	return 0;
}