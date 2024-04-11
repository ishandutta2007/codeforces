#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = 1110;
const int K = 110;
int n, k;
int p;
ll m, ans;


ll dp[N][K];
ll pow10[N], powK[N];

void init()
{
	pow10[0] = 1LL % m;
	powK[0] = 1 % k;
	for (int i = 1; i < N; i++)
	{
		pow10[i] = (pow10[i - 1] * 10LL) % m;
		powK[i] = (powK[i - 1] * 10) % k;
	}
	return;
}

void solve()
{
	p = 0;
	dp[0][0] = 1 % m;
	for (int l = 1; l <= n; l++)
	{
		for (int i = 0; i < k; i++)
			for (int j = 0; j < 10; j++)
				dp[l][(i + j * powK[l - 1]) % k] = (dp[l][(i + j * powK[l - 1]) % k] + dp[l - 1][i]) % m;
		dp[l][0] = (dp[l][0] + m - 1) % m;
		if (l < n)
			ans = (ans + dp[l][0] * (pow10[n - l - 1] * 9LL) % m) % m;
		else
			ans = (ans + dp[l][0]) % m;
		dp[l][0] = 1 % m;
	}
	return;
}

int main()
{
	cin >> n >> k >> m;
	ans = 0;
	init();
	solve();
	cout << ans % m << endl;

	return 0;
}