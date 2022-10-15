/*input
100000000000000 1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef long double ld;
using namespace __gnu_pbds;
ll n;
const int gen = 7;
cc_hash_table<ll, ll> X[gen + 1][2][10];
vector<ll>Y[gen + 1][2][10];
ll kiek(ll ilg, ll pir, ll tip, ll liek)
{	// tip 0 maziau, 1 daugiau
	if (ilg <= gen)
	{
		auto it = X[ilg][tip][pir].find(liek);
		if (it != X[ilg][tip][pir].end())
			return it->second;
		else return 0;
	}
	ll ret = 0;
	ll w = 1;
	for (int i = 0; i < ilg - gen; i++)
		w *= 10;
	for (ll x : Y[gen][tip][pir])
	{
		ll mod = liek - x * w;
		mod %= n;
		mod += n;
		mod %= n;
		if (tip == 0)
		{
			for (ll c = 0; c < (x % 10); c++)
			{
				ret += kiek(ilg - gen, c, 1 - tip, mod);
			}
		}
		if (tip == 1)
		{
			for (ll c = (x % 10) + 1; c < 10; c++)
			{
				ret += kiek(ilg - gen, c, 1 - tip, mod);
			}
		}
	}
	return ret;
}
ll kth(ll ilg, ll pir, ll tip, ll liek, ll k)
{	// tip 0 maziau, 1 daugiau
	if (ilg == 1)
		return pir;
	ll w = 1;
	for (int t = 1; t < ilg; t++)
		w *= 10;
	ll mod = liek;
	mod -= pir * w;
	mod %= n;
	mod += n;
	mod %= n;
	if (tip == 0)
	{
		for (ll a = 0; a < pir; a++)
		{
			ll x = kiek(ilg - 1, a, 1 - tip, mod);
			if (k - x <= 0)
				return w * pir + kth(ilg - 1, a, 1 - tip, mod, k);
			k -= x;
		}
	}
	if (tip == 1)
	{
		for (ll a = pir + 1; a < 10; a++)
		{
			ll x = kiek(ilg - 1, a, 1 - tip, mod);
			if (k - x <= 0)
				return w * pir + kth(ilg - 1, a, 1 - tip, mod, k);
			k -= x;
		}
	}
	return -3;
}
int main()
{
	clock_t pradzia = clock();
	ll k;
	cin >> n >> k;
	if (ll(1e14) / n < k)
	{
		cout << "-1\n";
		return 0;
	}
	for (ll t = 0; t <= 9; t++)
	{
		Y[1][0][t].push_back(t);
		Y[1][1][t].push_back(t);
	}
	ll w = 1;
	for (ll l = 2; l <= gen; l++)
	{
		w *= 10;
		for (int a = 0; a < 10; a++)
		{
			for (ll c : Y[l - 1][0][a])
			{
				for (ll h = 0; h < a; h++)
				{
					Y[l][1][h].push_back(c + h * w);
				}
			}
		}
		for (int a = 0; a < 10; a++)
		{
			for (ll c : Y[l - 1][1][a])
			{
				for (ll h = a + 1; h < 10; h++)
				{
					Y[l][0][h].push_back(c + h * w);
				}
			}
		}
	}
	for (ll l = 0; l <= gen; l++)
	{
		for (ll tip = 0; tip < 2; tip++)
		{
			for (ll c = 0; c < 10; c++)
			{
				for (ll i : Y[l][tip][c])
				{
					X[l][tip][c][i % n]++;
				}
			}
		}
	}
	cerr << double(clock() - pradzia) / CLOCKS_PER_SEC << '\n';
	for (ll l = 1; l <= 14; l++)
	{
		for (ll a = 1; a < 10; a++)
		{
			for (ll tip = 0; tip < 2; tip++)
			{
				if (tip == 1 && l == 1)
					continue;
				ll x = kiek(l, a, tip, 0);
				if (k - x <= 0)
				{
					cout << kth(l, a, tip, 0, k) << "\n";
					cerr << double(clock() - pradzia) / CLOCKS_PER_SEC << '\n';
					return 0;
				}
				k -= x;
			}
		}
	}
	cout << "-1\n";
}