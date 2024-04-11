/***
2 3 2 5
2 1 8
2 2 8
1 2 1
1 3 4
2 3 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF (2000000009ll)
ll A[1027][1027];
ll B[1027][1027][10];
ll z = 0;
ll sz = 1;
ll k;
ll get(ll i, ll j)
{
	return max(
	           max(B[i][j][z], B[i + k - sz][j][z]),
	           max(B[i][j + k - sz][z], B[i + k - sz][j + k - sz][z])
	       );
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m, q;
	cin >> n >> m >> k >> q;
	while (sz * 2 <= k)
	{
		sz *= 2;
		z++;
	}
	for (ll i = 0; i < 1027; i++)
		for (ll j = 0; j < 1027; j++)
			A[i][j] = INF;
	for (ll i = 0; i < 1027; i++)
		for (ll j = 0; j < 1027; j++)
			for (ll k = 0; k < 10; k++)
				B[i][j][k] = INF;
	while (q--)
	{
		ll x, y, t;
		cin >> x >> y >> t;
		A[x][y] = t;
	}
	for (ll i = 0; i < 1027; i++)
	{
		for (ll j = 0; j < 1027; j++)
		{
			B[i][j][0] = A[i][j];
		}
	}
	for (ll k = 1; k < 10; k++)
	{
		for (ll i = 0; i < 1027; i++)
		{
			for (ll j = 0; j < 1027; j++)
			{
				ll si = (1ll) << (k - 1);
				if (max(i, j) + si - 1 < 1027)
					B[i][j][k] = max(
					                 max(
					                     B[i][j][k - 1],
					                     B[i + si][j][k - 1]
					                 ),
					                 max(
					                     B[i][j + si][k - 1],
					                     B[i + si][j + si][k - 1]
					                 )
					             );
			}
		}
	}
	ll ans = INF;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			ans = min(ans, get(i, j));
		}
	}
	if (ans < INF)
		cout << ans;
	else
		cout << -1;
}