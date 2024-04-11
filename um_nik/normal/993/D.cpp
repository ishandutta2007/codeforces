#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair

const ll INF = (ll)1e18;
const ll C = (ll)1e14;
const int N = 55;
int n;
ll a[N][2];
pll b[N];
ll dp[N][N];

bool solve(ll X) {
	for (int i = 0; i < n; i++)
		b[i] = mp(a[i][0], a[i][0] - a[i][1] * X);
	sort(b, b + n);
	reverse(b, b + n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			dp[i][j] = INF;
	dp[0][0] = 0;
	int L = 0;
	while(L < n) {
		int R = L;
		while(R < n && b[L].first == b[R].first) R++;
		for (int was = 0; was <= L; was++) {
			if (dp[L][was] == INF) continue;
			ll sum = dp[L][was];
			for (int i = L; i < R; i++)
				sum += b[i].second;
			for (int cnt = 0; cnt <= R - L; cnt++) {
				if (cnt <= was)
					dp[R][was - cnt + R - L - cnt] = min(dp[R][was - cnt + R - L - cnt], sum);
				sum -= b[L + cnt].second;
			}
		}
		L = R;
	}
	for (int i = 0; i <= n; i++)
		if (dp[n][i] <= 0)
			return true;
	return false;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &a[j][i]);
	for (int i = 0; i < n; i++)
		a[i][0] *= 1000;
	ll L = 0, R = C;
	while(R - L > 1) {
		ll x = (L + R) / 2;
		if (solve(x))
			R = x;
		else
			L = x;
	}
	printf("%lld\n", R);

	return 0;
}