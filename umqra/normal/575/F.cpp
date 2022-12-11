#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <functional>
#include <cmath>
#include <ctime>
#include <valarray>
#include <complex>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;

const ll INF = (ll)1e17;
const int N = 10100;
int n;
ll x[N];
ll dp[2][N];
ll a[N][2];
ll S;
int m;

void read()
{
	scanf("%d%lld", &n, &S);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &a[i][0], &a[i][1]);
	m = 0;
	x[m++] = S;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
			x[m++] = a[i][j];
	sort(x, x + m);
	m = unique(x, x + m) - x;
	for (int i = 0; i < m; i++)
		dp[0][i] = INF;
	for (int i = 0; i < m; i++)
		if (x[i] == S)
			dp[0][i] = 0;
}

ll getDist(ll y, ll l, ll r)
{
	if (y < l) return l - y;
	if (y > r) return y - r;
	return 0;
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
#endif

	read();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			dp[1][j] = INF;
		ll val = INF;
		for (int j = 0; j < m; j++)
		{
			if (dp[0][j] != INF)
				val = min(val, dp[0][j] - x[j]);
			dp[1][j] = min(dp[1][j], val + x[j]);
		}
		val = INF;
		for (int j = m - 1; j >= 0; j--)
		{
			if (dp[0][j] != INF)
				val = min(val, dp[0][j] + x[j]);
			dp[1][j] = min(dp[1][j], val - x[j]);
		}
		for (int j = 0; j < m; j++)
			dp[0][j] = dp[1][j] + getDist(x[j], a[i][0], a[i][1]);
	}
	ll ans = INF;
	for (int i = 0; i < m; i++)
		ans = min(ans, dp[0][i]);
	printf("%lld\n", ans);

	return 0;
}