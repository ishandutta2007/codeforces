/*input
5 1
1 3 1 3 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	ll n, k;
	cin >> n >> k;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll r[30];
	ll p[30];
	ll kiek = 0;
	for (ll i = 2; i * i <= k; i++)
	{
		ll X = 0;
		while (k % i == 0)
		{
			X++;
			k /= i;
		}
		if (X > 0)
		{
			r[kiek] = X;
			p[kiek] = i;
			kiek++;
		}
	}
	if (k > 1)
	{
		r[kiek] = 1;
		p[kiek] = k;
		kiek++;
	}
	ll b[n][30];
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < kiek; j++)
		{
			b[i][j] = 0;
			while (a[i] % p[j] == 0)
			{
				b[i][j]++;
				a[i] /= p[j];
			}
		}
	}
	ll d[30];
	fill_n(d, 30, 0);
	ll ans = 0;
	ll desn = -1;
	for (ll l = 0; l < n; l++)
	{
		while (true)
		{
			bool negerai = false;
			for (ll i = 0; i < kiek; i++)
				if (d[i] < r[i])
					negerai = true;
			if (negerai)
			{
				desn++;
				if (desn >= n)
				{
					cout << ans << "\n";
					return 0;
				}
				for (ll c = 0; c < kiek; c++)
					d[c] += b[desn][c];
			}
			else
				break;
		}
		while (desn < l)
		{
			desn++;
			for (ll c = 0; c < kiek; c++)
				d[c] += b[desn][c];
		}
		ans += n - desn;
		for (ll c = 0; c < kiek; c++)
			d[c] -= b[l][c];
	}
	cout << ans << "\n";
	return 0;
}