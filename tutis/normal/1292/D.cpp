/*input
49
27 12 48 48 9 10 29 50 48 48 48 48 11 14 18 27 48 48 48 48 1 48 33 48 27 48 48 48 12 16 48 48 22 48 48 36 31 32 31 48 50 43 20 48 48 48 48 48 16
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
bool prime(ll x)
{
	for (ll y = 2; y * y <= x; y++)
	{
		if ((x % y) == 0)
			return false;
	}
	return true;
}
array<ll, 669> A[5001];
ll cnt[5001];
ll suma[5001];
ll kiek[700];
int main()
{
	vector<ll>P;
	for (ll i = 2; i <= 5000; i++)
		if (prime(i))
			P.push_back(i);
	for (ll i = 2; i <= 5000; i++)
	{
		suma[i] = suma[i - 1];
		for (ll t = 0; t < 669; t++)
		{
			A[i][t] = A[i - 1][t];
			ll x = i;
			while ((x % P[t]) == 0)
			{
				x /= P[t];
				A[i][t]++;
				suma[i]++;
			}
		}
	}
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll k;
		cin >> k;
		cnt[k]++;
	}
	array<ll, 669>lca;
	fill_n(lca.begin(), 669, 0);
	ll ans = 0;
	for (ll i = 0; i <= 5000; i++)
		ans += suma[i] * cnt[i];
	ll cntbad = 0;
	vector<ll>ok;
	for (ll i = 0; i <= 5000; i++)
		if (cnt[i] > 0)
			ok.push_back(i);
	ll vien[5001];
	for (ll i = 0; i <= 5000; i++)
	{
		vien[i] = 668;
		while (vien[i] >= 0 && A[i][vien[i]] == lca[vien[i]])
			vien[i]--;
		kiek[vien[i] + 1] += cnt[i];
	}
	ll j = 0;
	while (j + 1 < 669 && lca[j] == 0)
		j++;
	while (true)
	{
		bool change = false;
		for (ll i = 0; i <= j; i++)
		{
			ll gud = kiek[i + 1];
			ll bad = n - gud;
			if (gud > bad + cntbad)
			{
				vector<ll>ok1;
				for (ll a : ok)
				{
					kiek[vien[a] + 1] -= cnt[a];
					if (vien[a] == i)
						ok1.push_back(a);
				}
				ok = ok1;
				ll w = 5000;
				for (ll a : ok1)
					w = min(w, A[a][i] - lca[i]);
				lca[i] += w;
				for (ll a : ok1)
				{
					while (vien[a] >= 0 && A[a][vien[a]] == lca[vien[a]])
						vien[a]--;
					kiek[vien[a] + 1] += cnt[a];
				}
				n = gud;
				cntbad += bad;
				ans -= gud * w;
				ans += cntbad * w;
				change = true;
				j = i;
				break;
			}
		}
		if (!change)
			break;
	}
	cout << ans << "\n";
}