/*input
4 3 2 2
3 1 3 2
1 2
2 3
4 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n, m, s, k;
ll a[1500 + 1];
ll l[1500 + 1];
ll r[1500 + 1];
bool ok(ll x)
{
	ll b[n + 1];
	for (ll i = 1; i <= n; i++)
	{
		if (a[i] <= x)
			b[i] = 1;
		else
			b[i] = 0;
	}
	ll suma[n + 1][n + 1];
	for (ll a = 0; a <= n; a++)
	{
		for (ll b = 0; b <= n; b++)
		{
			suma[a][b] = 0;
		}
	}
	ll SUM[n + 1];
	SUM[0] = 0;
	for (ll i = 1; i <= n; i++)
		SUM[i] = SUM[i - 1] + b[i];
	for (ll i = 1; i <= s; i++)
	{
		for (ll L = l[i]; L <= r[i]; L++)
		{
			ll R = r[i];
			suma[L][R] = max(suma[L][R], SUM[R] - SUM[L - 1]);
		}
	}
	for (ll sz = 2; sz <= n; sz++)
	{
		for (ll l = 1; l + sz - 1 <= n; l++)
		{
			ll r = l + sz - 1;
			suma[l][r] = max({suma[l][r], suma[l + 1][r], suma[l][r - 1]});
		}
	}
	ll DP[n + 2][m + 2];
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= m; j++)
		{
			DP[i][j] = 0;
		}
	}
	multiset<ll>RR;
	vector<ll>plus[n + 5];
	vector<ll>minu[n + 5];
	for (ll j = 1; j <= s; j++)
	{
		plus[l[j] - 1].push_back(r[j]);
		minu[r[j] + 1].push_back(r[j]);
	}
	for (ll r = 0; r <= n; r++)
	{
		for (ll RRR : plus[r])
			RR.insert(RRR);
		for (ll RRR : minu[r])
			RR.erase(RR.find(RRR));
		ll r_ = -1;
		if (!RR.empty())
			r_ = *(--RR.end());
		for (ll a = 0; a < m; a++)
		{
			if (r_ >= r)
			{
				DP[r_][a + 1] = max(DP[r_][a + 1], DP[r][a] + SUM[r_] - SUM[r]);
			}
			DP[r + 1][a] = max(DP[r + 1][a], DP[r][a]);
		}
	}
	for (ll i = 0; i <= n; i++)
	{
		for (ll j = 0; j <= m; j++)
		{
			if (DP[i][m] >= k)
				return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> s >> m >> k;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= s; i++)
		cin >> l[i] >> r[i];
	ll lo = 0;
	ll hi = 1000000009;
	while (lo < hi)
	{
		ll m = (lo + hi) / 2;
		if (ok(m))
		{
			hi = m;
		}
		else
			lo = m + 1;
	}
	ll m = (lo + hi) / 2;
	if (m > 1000000000)
		m = -1;
	cout << m << "\n";
}