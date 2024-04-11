#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N = 50;
const int MOD = 1e9 + 7;

int n, T;
int t[N], g[N], suf[N];
int cache[N][N][N][3];
unordered_map<int, int> cache2[N][N * N];

int ways(int a, int b, int c, int prv)
{
	if(a < 0 || b < 0 || c < 0)
		return 0;
	if(a == 0 && b == 0 && c == 0)
		return 1;
	int &ans = cache[a][b][c][prv];
	if(ans != -1)
		return ans;
	ans = 0;
	if(prv != 0 && a > 0)
	{
		ans += (1LL * a * ways(a - 1, b, c, 0)) % MOD;
		ans %= MOD;
	}
	if(prv != 1 && b > 0)
	{
		ans += (1LL * b * ways(a, b - 1, c, 1)) % MOD;
		ans %= MOD;
	}
	if(prv != 2 && c > 0)
	{
		ans += (1LL * c * ways(a, b, c - 1, 2)) % MOD;
		ans %= MOD;
	}
	return ans;
}

int dp(int idx, int tim, int a, int b, int c)
{
	if(tim == T)
	{
		int ans = (1LL * a * ways(a - 1, b, c, 0)) % MOD;
		ans += (1LL * b * ways(a, b - 1, c, 1)) % MOD;
		ans %= MOD;
		ans += (1LL * c * ways(a, b, c - 1, 2)) % MOD;
		ans %= MOD;
		return ans;
	}
	if(suf[idx] + tim < T)
		return 0;
	if(idx >= n)
		return 0;
	int val = a * 51 * 51 + b * 51 + c;
	if(cache2[idx][tim].find(val) != cache2[idx][tim].end())
		return cache2[idx][tim][val];
	int &ans = cache2[idx][tim][val];
	ans = dp(idx + 1, tim, a, b, c);
	if(tim + t[idx] <= T)
	{
		int na = a, nb = b, nc = c;
		if(g[idx] == 0)
			na++;
		else if(g[idx] == 1)
			nb++;
		else
			nc++;
		ans += dp(idx + 1, tim + t[idx], na, nb, nc);
	}
	ans %= MOD;
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin >> n >> T;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i] >> g[i];
		g[i]--;
	}
	for(int i = n - 1; i >= 0; i--)
		suf[i] = suf[i + 1] + t[i];
	int ans = dp(0, 0, 0, 0, 0);
	cout << ans;
	return 0;
}