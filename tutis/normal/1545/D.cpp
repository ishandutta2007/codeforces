/*input
5 7
6 9 9 6 9
10 7 10 8 10
11 11 11 10 8
12 12 12 12 9
14 13 12 10 13
11 14 16 14 14
12 15 18 15 15

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll cntm = 5;
const array<ll, cntm> mod = {1000000007,
                             1000000009,
                             1000000021,
                             1000000033,
                             1000000087
                            };
array<ll, cntm> P(ll n, ll k)
{
	array<ll, cntm>ret;
	for (ll i = 0; i < cntm; i++)
	{
		ret[i] = 1;
		for (ll j = 0; j < k; j++)
		{
			ret[i] *= n;
			ret[i] %= mod[i];
		}
	}
	return ret;
}
array<ll, cntm>operator+(const array<ll, cntm>&a, const array<ll, cntm>&b)
{
	array<ll, cntm>ret;
	for (ll i = 0; i < cntm; i++)
	{
		ret[i] = a[i] + b[i];
		if (ret[i] >= mod[i])
			ret[i] -= mod[i];
	}
	return ret;
}
array<ll, cntm>operator-(const array<ll, cntm>&a, const array<ll, cntm>&b)
{
	array<ll, cntm>ret;
	for (ll i = 0; i < cntm; i++)
	{
		ret[i] = a[i] - b[i];
		if (ret[i] < 0)
			ret[i] += mod[i];
	}
	return ret;
}
ll power(ll x, ll p, ll m)
{
	if (p == 0)
		return 1;
	x %= m;
	if (x < 0)
		x += m;
	if (p % 2 == 1)
	{
		return (x * power(x, p - 1, m)) % m;
	}
	else
	{
		x = power(x, p / 2, m);
		return (x * x) % m;
	}
}
bool check(vector<array<ll, cntm>>C)
{
	bool ret = true;
	for (ll m = 0; m < cntm; m++)
	{
		vector<ll>y;
		for (ll i = 0; i < C.size(); i++)
			y.push_back(C[i][m]);
		ll x = (ll)C.size() - 1;
		ll suma = 0;
		for (ll j = 0; j < x; j++)
		{
			ll gal = y[j];
			for (ll k = 0; k < x; k++)
			{
				if (k == j)
					continue;
				gal *= (x - k);
				gal %= mod[m];
				gal *= power(j - k, mod[m] - 2, mod[m]);
				gal %= mod[m];
			}
			suma += gal;
			suma %= mod[m];
		}
		ret &= suma == y[x];
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll m, k;
	cin >> m >> k;
	ll x[k][m];
	for (ll i = 0; i < k; i++)
		for (ll j = 0; j < m; j++)
			cin >> x[i][j];
	ll suma[k];
	for (ll i = 0; i < k; i++)
	{
		suma[i] = 0;
		for (ll j = 0; j < m; j++)
			suma[i] += x[i][j];
	}
	ll yy = -1;
	for (ll y = 1; y < k - 1; y++)
	{
		vector<ll>gal;
		bool ok = true;
		for (ll i = 0; i < k; i++)
			if (i != y)
				gal.push_back(suma[i]);
			else
			{
				ok &= (suma[i - 1] + suma[i + 1]) % 2 == 0;
				gal.push_back((suma[i - 1] + suma[i + 1]) / 2);
			}
		for (ll i = 2; i < gal.size(); i++)
			ok &= (gal[i] - gal[i - 1]) == (gal[i - 1] - gal[i - 2]);
		if (ok)
		{
			assert(yy == -1);
			yy = y;
		}
	}
	const ll powm = 6;
	array<ll, cntm> suma1[k][powm];
	for (ll i = 0; i < k; i++)
	{
		for (ll j = 2; j < powm; j++)
		{
			for (ll a = 0; a < m; a++)
			{
				if (a == 0)
					suma1[i][j] = P(x[i][a], j);
				else
					suma1[i][j] = suma1[i][j] + P(x[i][a], j);
			}
		}
	}
	assert(yy != -1);
	cout << yy << " ";
	ll turi = (suma[yy + 1] + suma[yy - 1]) / 2;
	ll del = suma[yy] - turi;
	for (ll a = 0; a < m; a++)
	{
		for (ll j = 2; j < powm; j++)
			suma1[yy][j] = suma1[yy][j] - P(x[yy][a], j);
		x[yy][a] -= del;
		for (ll j = 2; j < powm; j++)
			suma1[yy][j] = suma1[yy][j] + P(x[yy][a], j);
		bool ok = true;
		for (ll j = 2; j < powm; j++)
		{
			ll cnt = j + 2;
			if (cnt <= k)
			{
				ll i0 = max(0ll, yy - cnt + 1);
				ll i1 = i0 + cnt - 1;
				vector<array<ll, cntm>>C;
				for (ll i = i0; i <= i1; i++)
					C.push_back(suma1[i][j]);
				ok &= check(C);
			}
		}
		if (ok)
		{
			cout << x[yy][a] << endl;
			return 0;
		}

		for (ll j = 2; j < powm; j++)
			suma1[yy][j] = suma1[yy][j] - P(x[yy][a], j);
		x[yy][a] += del;
		for (ll j = 2; j < powm; j++)
			suma1[yy][j] = suma1[yy][j] + P(x[yy][a], j);
	}
}