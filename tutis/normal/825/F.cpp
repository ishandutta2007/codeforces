/*input
aaaaaaaaaa
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
int kiek[8000][8001];
int ilg(int n)
{
	int ans = 0;
	while (n > 0)
	{
		ans++;
		n /= 10;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	string s;
	cin >> s;
	ll base = 39 + rand() * 10;
	int n = s.size();
	int dp[n];
	for (int i = 0; i < n; i++)
		dp[i] = i + 2;
	ll H[n];
	ll P[n + 1];
	P[0] = 1;
	for (int i = 1; i <= n; i++)
		P[i] = (P[i - 1] * base) % modulo;
	for (int i = 0; i < n; i++)
	{
		H[i] = ll(s[i] - 'a' + 1) * P[i];
		if (i > 0)
			H[i] += H[i - 1];
		H[i] %= modulo;
	}
	auto HASH = [&](int l, int r)
	{
		ll SUM = H[r];
		if (l - 1 >= 0)
			SUM -= H[l - 1];
		SUM %= modulo;
		SUM += modulo;
		SUM %= modulo;
		return (SUM * P[n - r]) % modulo;
	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n && i - j + 1 >= 0; j++)
		{
			if (i - j - j + 1 >= 0 && HASH(i - j + 1, i) == HASH(i - j - j + 1, i - j))
				kiek[i][j] = 1 + kiek[i - j][j];
			else
				kiek[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n && i - j + 1 >= 0; j++)
		{
			for (int a = 1; a <= kiek[i][j]; a++)
			{
				if (dp[i] <= j + 1)
					break;
				if (i - j * a >= 0)
					dp[i] = min(dp[i], j + ilg(a) + dp[i - j * a]);
				else
					dp[i] = min(dp[i], j + ilg(a));
			}
		}
	}


	cout << dp[n - 1] << "\n";
}