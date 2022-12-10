#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) (void)0
#endif

using ll = long long;
using pii = pair<int, int>;

const int N = 3e5 + 10;
int n, k;
int v[N];
pii st[N];
int sz;
int dp[N];

void solve()
{
	memset(dp, -1, sizeof dp);
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", &v[i]);
	sort(v, v + n);
	st[sz++] = {0, v[0]};
	for (int i = k - 1; i < n; ++i)
	{
		if (i >= k && dp[i - k] != -1)
		{
			while (sz > 0 && st[sz - 1].first >= dp[i - k])
				--sz;
			st[sz++] = {dp[i - k], v[i - k + 1]};
		}
		int l = 0;
		int r = sz;
		while(r - l > 1)
		{
			auto m = (l + r) / 2;
			if (st[m].first > (v[i] - st[m].second))
				r = m;
			else
				l = m;
		}
		dp[i] = (v[i] - st[l].second);
		if (r != sz)
			dp[i] = min(dp[i], st[r].first);
	}
	printf("%d\n", dp[n - 1]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("err.txt", "w", stderr);
#endif

	solve();

	eprintf("\n\ntime = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}