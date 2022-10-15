/*input
3 4 2 1
1 2 3 59
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll g[n * m];
	cin >> g[0];
	ll x, y, z;
	cin >> x >> y >> z;
	for (ll i = 1; i < n * m; i++)
	{
		g[i] = (g[i - 1] * x + y) % z;
	}
	ll A[n][m];
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			A[i][j] = g[i * m + j];
		}
	}
	ll B[n - a + 1][m];
	for (ll j = 0; j < m; j++)
	{
		deque<ll>X;
		for (ll i = 0; i < n; i++)
		{
			while (!X.empty() && A[X.back()][j] >= A[i][j])
				X.pop_back();
			X.push_back(i);
			if (i >= a - 1)
			{
				while (X.front() <= i - a)
					X.pop_front();
				B[i - a + 1][j] = A[X.front()][j];
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n - a + 1; i++)
	{
		deque<ll>X;
		for (int j = 0; j < m; j++)
		{
			while (!X.empty() && B[i][X.back()] >= B[i][j])
				X.pop_back();
			X.push_back(j);
			if (j >= b - 1)
			{
				while (X.front() <= j - b)
					X.pop_front();
				ans += B[i][X.front()];
			}
		}
	}
	cout << ans << "\n";
}