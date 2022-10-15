/*input
1 3 1
1 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m, reik;
	cin >> n >> m >> reik;
	ll A[n][m];
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
			cin >> A[i][j];
	}

	ll k = (n + m - 2) / 2;
	queue<pair<pair<ll, ll>, pair<ll, ll>>>Q;
	Q.push({{0, 0}, {A[0][0], 0}});
	map<ll, ll>M[n][m];
	while (!Q.empty())
	{
		pair<pair<ll, ll>, pair<ll, ll>>a = Q.front();
		Q.pop();
		ll x = a.first.first;
		ll y = a.first.second;
		ll xo = a.second.first;
		ll at = a.second.second;
		if (at == k)
		{
			if (M[x][y].count(xo))
				M[x][y][xo]++;
			else
				M[x][y][xo] = 1;
			continue;
		}
		if (x + 1 < n)
		{
			Q.push({{x + 1, y}, {xo^A[x + 1][y], at + 1}});
		}
		if (y + 1 < m)
		{
			Q.push({{x, y + 1}, {xo^A[x][y + 1], at + 1}});
		}
	}
	ll ans = 0;
	ll att = (n + m - 2);
	Q.push({{n - 1, m - 1}, {A[n - 1][m - 1], att}});
	while (!Q.empty())
	{
		pair<pair<ll, ll>, pair<ll, ll>>a = Q.front();
		Q.pop();
		ll x = a.first.first;
		ll y = a.first.second;
		ll xo = a.second.first;
		ll at = a.second.second;
		if (at == k)
		{
			if (M[x][y].count(xo ^ reik ^ A[x][y]))
				ans += M[x][y][xo ^ reik ^ A[x][y]];
			continue;
		}
		if (x - 1 >= 0)
		{
			Q.push({{x - 1, y}, {xo^A[x - 1][y], at - 1}});
		}
		if (y - 1 >= 0)
		{
			Q.push({{x, y - 1}, {xo^A[x][y - 1], at - 1}});
		}
	}
	cout << ans << "\n";
}