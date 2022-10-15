/*input
5
1 2
1 3
1 4
2 5

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
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll F[202][202];
	for (int a = 0; a < 202; a++)
	{
		for (int b = 0; b < 202; b++)
		{
			if (a == 0)
				F[a][b] = 1;
			else if (b == 0)
				F[a][b] = 0;
			else
				F[a][b] = ((F[a - 1][b] + F[a][b - 1]) * power(2, -1)) % mod;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ll gal = 0;
		int D[n + 1];
		function<vector<int>(int, int)>dfs = [&](int i, int p)
		{
			vector<vector<int>>V;
			V.push_back({i});
			for (int j : adj[i])
			{
				if (j != p)
				{
					D[j] = D[i] + 1;
					V.push_back(dfs(j, i));
				}
			}
			vector<int>W;
			for (vector<int>&i : V)
			{
				for (int x : i)
					W.push_back(x);
			}
			int dd = D[i];
			for (int i = 0; i < V.size(); i++)
			{
				for (int j = 0; j < i; j++)
				{
					for (int x : V[i])
					{
						for (int y : V[j])
						{
							int d1 = D[x] - dd;
							int d2 = D[y] - dd;
							if (x > y)
								gal += F[d1][d2];
							else
								gal += F[d2][d1];
							if (gal >= mod)
								gal -= mod;
						}
					}
				}
			}
			return W;
		};
		D[i] = 0;
		dfs(i, i);
		ans += gal;
		ans %= mod;
	}
	ans = ans * power(n, -1);
	ans %= mod;
	cout << ans << "\n";
}