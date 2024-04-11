#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int INF = (int)1e9;
const int N = 21;
string s[N];
int n, m;
int dp[1 << N];
int k;
int mv[2 * N * N][2];
int c[N][N];

void read()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c[i][j];
	for (int i = 0; i < n; i++)
	{
		int x = INF;
		for (int j = 0; j < m; j++)
		{
			bool ok = true;
			for (int p = 0; p < n; p++)
			{
				if (p == i) continue;
				if (s[i][j] == s[p][j]) ok = false;
			}
			if (ok)
				x = 0;
			else
				x = min(x, c[i][j]);
		}
		mv[k][0] = 1 << i;
		mv[k][1] = x;
		k++;
	}
	for (int j = 0; j < m; j++)
		for (int l = 'a'; l <= 'z'; l++)
		{
			int mask = 0;
			int sum = 0;
			int mm = 0;
			for (int i = 0; i < n; i++)
			{
				if (s[i][j] != l) continue;
				mask |= 1 << i;
				sum += c[i][j];
				mm = max(mm, c[i][j]);
			}
			if (mask == 0) continue;
			sum -= mm;
			mv[k][0] = mask;
			mv[k][1] = sum;
			k++;
		}
	return;
}

void solve()
{
	for (int i = 0; i < (1 << n); i++)
		dp[i] = INF;
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (dp[mask] == INF) continue;
		for (int i = 0; i < k; i++)
		{
			int nmask = mask | mv[i][0];
			int w = dp[mask] + mv[i][1];
			dp[nmask] = min(dp[nmask], w);
		}
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return;
}

int main()
{
	read();
	solve();

	return 0;
}