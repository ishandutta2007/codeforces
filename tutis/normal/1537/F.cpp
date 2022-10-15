/*input
2
4 4
5 1 2 -3
3 3 10 1
1 2
1 4
3 2
3 4
4 4
5 8 6 6
-3 1 15 4
1 2
1 4
3 2
3 4

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
const ll mod = 998244353;
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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int v[n + 1];
		int t[n + 1];
		vector<int>adj[n + 1];
		{
			ll bal = 0;
			for (int i = 1; i <= n; i++)
			{
				cin >> v[i];
				bal += v[i];
			}
			for (int i = 1; i <= n; i++)
			{
				cin >> t[i];
				bal -= t[i];
			}
			while (m--)
			{
				int i, j;
				cin >> i >> j;
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
			if (bal % 2 != 0) {
				cout << "NO\n";
				continue;
			}
		}
		bool col[n + 1];
		vector<bool>vis(n + 1, false);
		bool yra = false;
		function<void(int)>dfs = [&](int x)
		{
			for (int y : adj[x])
			{
				if (!vis[y])
				{
					vis[y] = true;
					col[y] = !col[x];
					dfs(y);
				}
				else
				{
					if (col[x] == col[y])
						yra = true;
				}
			}
		};
		vis[1] = true;
		col[1] = false;
		dfs(1);
		ll bal = 0;
		for (int i = 1; i <= n; i++)
			if (col[i])
				bal += t[i] - v[i];
			else
				bal -= t[i] - v[i];
		if (yra || bal == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}