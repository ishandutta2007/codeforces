#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <utility>
#include <cstring>
#include <cassert>
#include <cmath>
#include <stack>
#include <queue>
#include <ctime>
#define ll long long
#define next nex 

using namespace std;

const int maxn = (int)1e6 + 10;

const ll mod = (int)1e9 + 7;
pair <int, int> v[maxn];
int next[maxn];
ll cont[maxn];
ll cc[maxn];
vector <vector <ll> > dp;
int n, k;
ll l;

ll go(int pos, int cnt, bool st) {
	if (dp[pos][cnt] == -1) {
		if (cnt == 0) {
			dp[pos][cnt] = 1;
		} else if (pos == n) {
			dp[pos][cnt] = 0;
		} else {
			dp[pos][cnt] = 0;
			if (cnt != 1 || st) {
				dp[pos][cnt] += (ll)(next[pos] - pos + 1) * go(pos, cnt - 1, st);
			} else {
				dp[pos][cnt] += (ll)(cont[pos]) * go(pos, cnt - 1, st);
			}

			dp[pos][cnt] += go(next[pos] + 1, cnt, st);
			dp[pos][cnt] %= mod;
		}
	}

	return dp[pos][cnt];
}

int main() {
	cin >> n >> l >> k;

	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i].first);

		v[i].second = i;
	}

	while ((ll)(k - 1) * n > l) {
		k--;
	}

	sort(v, v + n);

	next[n - 1] = n - 1;
	cont[n - 1] = 0;
	cc[n - 1] = 1;

	if (v[n - 1].second < l % n) {
		cont[n - 1] = 1;
	}

	for (int i = n - 2; i >= 0; i--) {
		if (v[i].first == v[i + 1].first) {
			next[i] = next[i + 1];

			cont[i] = cont[i + 1];

			if (v[i].second < l % n) {
				cont[i]++;
			}

			cc[i] = cc[i + 1] + 1;
		} else {
			next[i] = i;
			cont[i] = 0;
			cc[i] = 1;

			if (v[i].second < l % n) {
				cont[i] = 1;
			}
		}
	}

	dp.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		dp[i].assign(k + 1, -1);
	}

	for (int i = 0; i <= n; i = next[i] + 1) {
		for (int j = 1; j <= k; j++) {
			go(i, j, 1);
		}
		if (i == n) {
			break;
		}
	}

	vector <vector <ll> > d;

	d = dp;

	for (int i = 0; i <= n; i++) {
		dp[i].assign(k + 1, -1);
	}

	for (int i = 0; i <= n; i = next[i] + 1) {
		for (int j = 1; j <= k; j++) {
			go(i, j, 0);
		}
		if (i == n) {
			break;
		}
	}

	ll f = l / n;

	ll ans = 0;

	for (int i = 1; i <= k; i++) {
		ll g = f - i + 1;

		if (g >= 0) {
			g %= mod;
			ans += g * d[0][i];
			ans += dp[0][i];
			ans %= mod;
		}
	}

	cout << ans << endl;

	return 0;
}