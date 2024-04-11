#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e17;

const int N = 3030;
ll a[N];
ll b[N];
ll dp[2][N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] -= i;
		b[i] = a[i];
	}
	sort(b, b + n);
	m = unique(b, b + n) - b;
	for (int i = 0; i < n; i++)
	{
		ll val = INF;
		for (int j = 0; j < m; j++)
		{
			val = min(dp[0][j], val);
			dp[1][j] = val + abs(a[i] - b[j]);
		}
		for (int j = 0; j < m; j++)
			dp[0][j] = dp[1][j];
	}
	ll ans = INF;
	for (int j = 0; j < m; j++)
		ans = min(ans, dp[0][j]);
	printf("%lld\n", ans);

	return 0;
}