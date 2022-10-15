/*input
5
1 5 2 11 14

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
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
ll scc[1 << 14];
ll los[1 << 14][14];
ll one[1 << 14][14];
ll oneq[1 << 14][14];
ll all[1 << 14][14];
ll allq[1 << 14][14];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll p[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = (a[i] * power(a[i] + a[j], -1)) % mod;
		}
	}
	for (int i = 0; i < n; i++)
	{
		all[0][i] = 1;
		allq[0][i] = 1;
	}
	for (int msk = 1; msk < (1 << n); msk++)
	{
		for (int i = 0; i < n; i++)
		{
			if ((msk & (1 << i)) != 0)
			{
				for (int x = 0; x < n; x++)
				{
					if ((msk & (1 << x)) == 0)
					{
						one[msk][x] = p[i][x] + p[x][i] * one[msk ^ (1 << i)][x];
						one[msk][x] %= mod;
						oneq[msk][x] = p[x][i] + p[i][x] * oneq[msk ^ (1 << i)][x];
						oneq[msk][x] %= mod;
						all[msk][x] = p[i][x] * all[msk ^ (1 << i)][x];
						all[msk][x] %= mod;
						allq[msk][x] = p[x][i] * allq[msk ^ (1 << i)][x];
						allq[msk][x] %= mod;
					}
				}
				break;
			}
		}
	}
	for (int msk = 1; msk < (1 << n); msk++)
	{
		if (msk == (msk & (-msk)))
			scc[msk] = 1;
		else
			for (int i = 0; i < n; i++)
			{
				if ((msk & (1 << i)) != 0)
				{
					int msk1 = msk ^ (1 << i);
					scc[msk] = scc[msk1] * (one[msk1][i] - all[msk1][i]);
					scc[msk] %= mod;
					for (int sub = (msk1 - 1)&msk1; sub != 0; sub = (sub - 1)&msk1)
					{
						int sub1 = msk1 ^ sub;
						ll gal = scc[sub] * one[sub][i];
						gal %= mod;
						for (int i = 0; i < n; i++)
						{
							if ((sub & (1 << i)) != 0)
							{
								gal *= all[sub1][i];
								gal %= mod;
							}
						}
						gal *= los[sub1][i];
						scc[msk] += gal;
						scc[msk] %= mod;
					}
					break;
				}
			}
		for (int sub = msk; sub != 0; sub = (sub - 1)&msk)
		{
			ll gal = scc[sub];
			for (int i = 0; i < n; i++)
			{
				if ((msk & (1 << i)) != 0 && (sub & (1 << i)) == 0)
				{
					gal *= all[sub][i];
					gal %= mod;
				}
			}
			for (int x = 0; x < n; x++)
			{
				if ((msk & (1 << x)) == 0)
				{
					los[msk][x] += gal * oneq[sub][x];
					los[msk][x] %= mod;
				}
			}
		}
	}
	ll ans = 0;
	for (int msk = 1; msk < (1 << n); msk++)
	{
		ll gal = scc[msk];
		for (int i = 0; i < n; i++)
		{
			if (((msk) & (1 << i)) != 0)
			{
				for (int j = 0; j < n; j++)
					if (((msk) & (1 << j)) == 0)
					{
						gal *= p[i][j];
						gal %= mod;
					}
			}
		}
		gal *= __builtin_popcount(msk);
		ans += gal;
		ans %= mod;
	}
	if (ans < 0)
		ans += mod;
	cout << ans << "\n";
}