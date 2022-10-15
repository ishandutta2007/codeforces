/*input
5 3 5
5 -5 5 1 -4
2 1 2
4 2 1 4 5
2 2 5
? 2
+ 3 4
? 1
+ 2 1
? 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll>xx[100000 + 1];
ll Sum[100000 + 1];
vector<ll>elem[100000 + 1];
ll Pridek[100000 + 1];
ll a[100000 + 1];
ll b[100000 + 1];
bool buvo[100000 + 1];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m, q;
	cin >> n >> m >> q;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	for (ll i = 1; i <= m; i++)
	{
		ll k;
		cin >> k;
		while (k--)
		{
			ll c;
			cin >> c;
			xx[c].push_back(i);
			elem[i].push_back(c);
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j : xx[i])
		{
			Sum[j] += a[i];
		}
		a[i] = 0;
	}
	vector<ll>Dideli;
	vector<ll>KKK[m + 1];
	map<ll, ll>ID;
	ll yra[n + 1];
	fill_n(yra, n + 1, 0);
	for (ll i = 1; i <= m; i++)
	{
		if (elem[i].size() > 500)
		{
			ID[i] = Dideli.size();
			Dideli.push_back(i);
			for (ll j : elem[i])
			{
				yra[j] = 1;
			}
			for (ll i = 1; i <= m; i++)
			{
				ll kiek = 0;
				for (ll j : elem[i])
				{
					kiek += yra[j];
				}
				KKK[i].push_back(kiek);
			}
			for (ll j : elem[i])
			{
				yra[j] = 0;
			}
		}
	}
	vector<ll>X;
	while (q--)
	{
		char x;
		cin >> x;
		if (x == '?')
		{
			ll k;
			cin >> k;
			if (X.size() >= 500)
			{
				for (ll i = 1; i <= n; i++)
				{
					for (ll j : xx[i])
					{
						Sum[j] += a[i];
					}
					a[i] = 0;
				}
				for (ll i = 1; i <= m; i++)
					b[i] = 0;
				X.clear();
			}
			ll ans = Sum[k];
			if (elem[k].size() > 500)
			{
				ll x = ID[k];
				for (ll i : X)
				{
					if (buvo[i])
						continue;
					buvo[i] = true;
					ans += KKK[i][x] * b[i];
				}
			}
			else
			{
				for (int i : elem[k])
				{
					ans += a[i];
				}
			}
			for (ll i : X)
				buvo[i] = false;
			for (ll c = 0; c < Dideli.size(); c++)
			{
				ans += KKK[k][c] * Pridek[Dideli[c]];
			}
			cout << ans << "\n";
		}
		else
		{
			ll k, x;
			cin >> k >> x;
			if (elem[k].size() <= 500)
			{
				for (ll i : elem[k])
				{
					a[i] += x;
				}
				b[k] += x;
				X.push_back(k);
			}
			else
			{
				Pridek[k] += x;
			}
		}
	}
}