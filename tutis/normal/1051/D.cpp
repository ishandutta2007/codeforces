/*input
3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353ll;
ll XXX[1001][2001][2][2];
ll kiek(int n, int k, int a, int b)
{
	if (k < 1)
		return 0;
	if (a == 1)
	{
		a ^= 1;
		b ^= 1;
	}
	if (XXX[n][k][a][b] != -1)
		return XXX[n][k][a][b];
	if (n == 1)
	{
		if (a == b)
			return k == 1;
		return k == 2;
	}
	ll ans = 0;
	if (a == 0 && b == 0)
	{
		ans += kiek(n - 1, k, 0, 0);
		ans += kiek(n - 1, k, 0, 1) * 2;
		ans += kiek(n - 1, k - 1, 1, 1);
		ans %= modulo;
		return XXX[n][k][a][b] = ans;
	}
	ans += kiek(n - 1, k - 1, 0, 0) * 2;
	ans += kiek(n - 1, k, 0, 1);
	ans += kiek(n - 1, k - 2, 1, 0);
	ans %= modulo;
	return XXX[n][k][a][b] = ans;
}
int main()
{
	for (int i = 0; i < 1001; i++)
	{
		for (int j = 0; j < 2001; j++)
		{
			for (int a : {0, 1})
				for (int b : {0, 1})
				{
					XXX[i][j][a][b] = -1;
				}
		}
	}
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	ll ans = 0;
	for (int a : {0, 1})
		for (int b : {0, 1})
		{
			ans += kiek(n, k, a, b);
			ans %= modulo;
		}
	cout << ans << "\n";
}