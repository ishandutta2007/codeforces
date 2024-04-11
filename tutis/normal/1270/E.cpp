/*input
3
0 0
0 1
1 0

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n;
ll x[1010], y[1010];
ll t[1010];
vector<ll>p;
map<ll, bool>M;
ll d(ll i, ll j)
{
	i = p[i];
	j = p[j];
	ll a = x[i] - x[j];
	ll b = y[i] - y[j];
	return a * a + b * b;
}
void ieskok(ll i)
{
	if (i == n)
	{
		ll kiek = 0;
		for (ll i = 0; i < n; i++)
		{
			if (t[i] == 0)
				kiek++;
		}
		if (kiek == 0 || kiek == n)
			return;
		cout << kiek << "\n";
		for (ll i = 0; i < n; i++)
		{
			if (t[i] == 0)
				cout << i + 1 << " ";
		}
		cout << "\n";
		exit(0);
	}
	for (t[p[i]] = 0; t[p[i]] <= 1; t[p[i]]++)
	{
		bool ok = true;
		for (ll j = 0; j < i; j++)
		{
			bool x = t[p[i]] != t[p[j]];
			ll di = d(i, j);
			if (M.count(di))
			{
				if (M[di] != x)
				{
					ok = false;
					break;
				}
			}
		}
		if (ok)
		{
			vector<ll>at;
			for (ll j = 0; j < i; j++)
			{
				bool x = t[p[i]] != t[p[j]];
				ll di = d(i, j);
				if (M.count(di) == false)
				{
					M[di] = x;
					at.push_back(j);
				}
				else
				{
					if (M[di] != x)
					{
						ok = false;
						break;
					}
				}
			}
			if (ok)
				ieskok(i + 1);
			for (ll j : at)
			{
				M.erase(d(i, j));
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		p.push_back(i);
	}
	t[p[0]] = 1;
	ieskok(1);
}