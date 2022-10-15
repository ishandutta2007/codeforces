/*input
5
3 3
5 15
4 13
6 8
4 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll D[51];
ll F[51];
ld D_[51];
ld F_[51];
ll kiek(ll n)
{
	if (n == 0)
		return 1;
	if (D[n] != 0)
		return D[n];
	ll ret = 0;
	ld ret_ = 0;
	for (ll x = 1; x <= n; x++)
	{
		ret += (x == 1 ? 1ll : F[x - 2]) * kiek(n - x);
		ret_ += (x == 1 ? ld(1) : F_[x - 2]) * D_[n - x];
	}
	if (ret_ >= 1.1e18)
	{
		ret_ = 1e19;
		ret = 1e18 + 2;
	}
	D_[n] = ret_;
	return D[n] = ret;
}
ll kiek(vector<ll>a, ll x)
{
	for (ll i = 0; i < (ll)a.size(); i++)
	{
		for (ll j = 0; j < i; j++)
		{
			if (a[i] == a[j])
				return 0;
		}
	}
	if ((ll)a.size() == x)
	{
		vector<bool>ok(x, false);
		ll v = a[0];
		for (ll t = 0; t < x; t++)
		{
			v = a[v];
			ok[v] = true;
		}
		for (bool i : ok)
			if (i == false)
				return 0;
		return 1;
	}
	for (ll i = 0; i < (ll)a.size(); i++)
	{
		ll v = a[i];
		for (ll t = 0; t <= x; t++)
		{
			if (v >= (ll)a.size())
				break;
			v = a[v];
			if (v == i)
			{
				return 0;
			}
		}
	}
	ll k = x - (ll)a.size() - 1;
	return F[k];
}
vector<ll>ieskok(ll x, ll k)
{
	vector<ll>r = {x - 1};
	for (ll i = 1; i < x; i++)
	{
		r.push_back(0);
		for (r.back() = 0; r.back() < x; r.back()++)
		{
			ll vv = kiek(r, x);
			if (vv >= k)
			{
				break;
			}
			else
			{
				k -= vv;
			}
		}
	}
	return r;
}
void spresk(ll n, ll k, ll delta)
{
	if (n == 0)
	{
		cout << "\n";
		return;
	}
	if (D[n] < k)
	{
		cout << "-1\n";
		return;
	}
	for (ll x = 1; x <= n; x++)
	{
		ll kiek = (x == 1 ? 1ll : F[x - 2]) * D[n - x];
		ld kiek_ = (x == 1 ? ld(1) : F_[x - 2]) * D_[n - x];
		if (kiek_ >= 2e18)
			kiek = 1e18;
		if (kiek < k)
		{
			k -= kiek;
		}
		else
		{
			ll a = D[n - x];
			ll kart = (k - 1) / a + 1;
			k -= (kart - 1) * a;
			if (x == 1)
			{
				cout << 1 + delta << " ";
			}
			else
			{
				for (ll i : ieskok(x, kart))
					cout << i + 1 + delta << " ";
			}
			spresk(n - x, k, delta + x);
			return;
		}
	}
}
int main()
{
	F[0] = 1;
	F_[0] = 1;
	D[0] = 1;
	D_[0] = 1;
	for (ll i = 1; i < 50; i++)
	{
		F[i] = F[i - 1] * i;
		F_[i] = F_[i - 1] * ld(i);
	}
	kiek(50);
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		spresk(n, k, 0);
	}
}