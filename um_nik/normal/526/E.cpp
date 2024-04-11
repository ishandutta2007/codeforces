#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef long long ll;

const int L = (1 << 20);
const int N = L << 1;
const int LOG = 21;
int n;
ll a[L];
ll sums[N];
int q;
ll b;
int ans;

int nxt[L];

int dp[L][2];

void init()
{
	sums[0] = 0;
	for (int i = 0; i < 2 * n; i++)
		sums[i + 1] = sums[i] + a[(i < n ? i : i - n)];
	return;
}

void build()
{
	int r = 0;
	for (int i = 0; i < n; i++)
	{
		while(sums[r + 1] - sums[i] <= b) r++;
		nxt[i] = r;
	}
	return;
}

int query()
{
	scanf("%I64d", &b);
	if (sums[n] <= b) return 1;
	ans = n;

	build();
/*
	for (int i = 0; i < n; i++)
		printf("%d : %d\n", i, nxt[i]);
*/
	for (int x = n - 1; x >= 0; x--)
	{
		int y = nxt[x];
		if (y >= n)
		{
			dp[x][0] = 1;
			dp[x][1] = y - n;
			continue;
		}
		dp[x][0] = dp[y][0] + 1;
		dp[x][1] = dp[y][1];
	}
/*
	for (int i = 0; i < n; i++)
		printf("%d : %d %d\n", i, dp[i][0], dp[i][1]);
*/
	for (int i = 0; i <= nxt[0]; i++)
	{
		if (dp[i][1] >= i)
			ans = min(ans, dp[i][0]);
		else
			ans = min(ans, dp[i][0] + 1);
	}

	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	init();
	while(q--)
		printf("%d\n", query());

	return 0;
}