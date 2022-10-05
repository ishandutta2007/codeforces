#include <bits/stdc++.h>
using namespace std;

const int Maxn = 19;
int n;
long long ans[1 << Maxn | 5], f[1 << Maxn | 5][Maxn], A[Maxn][1 << Maxn | 5], g[Maxn][1 << Maxn | 5];
bool G[Maxn][Maxn];
vector <int> Ve;
map <vector <int>, long long> Ma;
void FWT(long long now[], int len, void (*add)(long long &x, long long &y))
{
	for (int i = 1; i <= len; i <<= 1)
		for (int j = 0; j < len; j += (i << 1))
			for (int k = j; k < i + j; k++)
				add(now[k], now[i + k]);
}
void dfs(int lim, int las)
{
	if (!lim)
	{
		long long tot = 0;
		for (int i = 0; i < (1 << n); i++)
			tot += ((n & 1) ^ __builtin_parity(i)) ? -g[0][i] : g[0][i];
		Ma[Ve] = tot;
	}
	else
	{
		for (int i = las; 2 * i <= lim; i++)
		{
			for (int j = 0; j < (1 << n); j++)
				g[lim - i][j] = A[i][j] * g[lim][j];
			Ve.push_back(i);
			dfs(lim - i, i);
			Ve.pop_back();
		}
		for (int i = 0; i < (1 << n); i++)
			g[0][i] = A[lim][i] * g[lim][i];
		Ve.push_back(lim);
		dfs(0, 0);
		Ve.pop_back();
	}
}
long long cal(int x)
{
	Ve.clear();
	int las = -1;
	for (int i = 0; i < n; i++)
		if (!(x & (1 << i)))
			Ve.push_back(i - las), las = i;
	sort(Ve.begin(), Ve.end());
	return Ma[Ve];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int x;
			scanf("%1d", &x);
			G[i][j] = x;
		}
	int maxi = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
		f[1 << (i - 1)][i] = 1;
	for (int i = 1; i <= maxi; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][j])
				for (int k = 1; k <= n; k++)
				if (!(i & (1 << (k - 1))) && G[j][k])
					f[i ^ (1 << (k - 1))][k] += f[i][j];
	for (int i = 1; i <= maxi; i++)
		for (int j = 1; j <= n; j++)
			A[__builtin_popcount(i)][i] += f[i][j];
	for (int i = 1; i <= n; i++) FWT(A[i], 1 << n, [] (long long &x, long long &y) { y += x; });
	for (int i = 0; i <= maxi; i++) g[n][i] = 1;
	dfs(n, 1);
	for (int i = 0; i < (1 << (n - 1)); i++)
		ans[i] = cal(i);
	FWT(ans, 1 << (n - 1), [] (long long &x, long long &y) { x -= y; });
	for (int i = 0; i < (1 << (n - 1)); i++)
		printf("%lld ", ans[i]);
	return 0;
}