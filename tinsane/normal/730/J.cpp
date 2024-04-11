#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

typedef long long ll;
const int N = 105;
const int S = 10500;
const int INF = (int)1e9;

int n;
int a[N], b[N];
pair<int, int> dp[N][2 * S + 1];

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 0; i <= n; i++)
		for (int s = -S; s <= S; s++)
			dp[i][s + S] = { INF, INF };
	dp[0][0 + S] = { 0, 0 };

	for (int i = 0; i < n; i++)
		for (int s = -S; s <= S; s++)
		{
			auto val = dp[i][s + S];
			if (val.first == INF)
				continue;

			int new_s = s + a[i];
			pair<int, int> cost = { val.first, val.second + a[i] };
			if (dp[i + 1][new_s + S] > cost)
				dp[i + 1][new_s + S] = cost;

			new_s = s - (b[i] - a[i]);
			cost = { val.first + 1, val.second };
			if (dp[i + 1][new_s + S] > cost)
				dp[i + 1][new_s + S] = cost;
		}

	pair<int, int> ans = { INF, INF };
	for (int s = -S; s <= 0; s++)
		ans = min(ans, dp[n][s + S]);
	printf("%d %d\n", ans.first, ans.second);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
#endif

	solve();

	eprintf("\n\ntime: %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

	return 0;
}