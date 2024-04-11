/*input
4
4
1 2 3
1 2 3
5
1 2 3 4
1 1 1 1
6
1 1 1 1 2
1 2 1 2 2
7
1 1 3 4 4 5
1 2 1 4 2 5

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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>adj1[n + 1];
		vector<int>adj2[n + 1];
		for (int i = 2; i <= n; i++)
		{
			int p;
			cin >> p;
			adj1[p].push_back(i);
		}
		for (int i = 2; i <= n; i++)
		{
			int p;
			cin >> p;
			adj2[p].push_back(i);
		}
		int l[n + 1], r[n + 1];
		int timer = 0;
		{
			function<void(int, int)>dfs2 = [&](int i, int p)
			{
				timer++;
				l[i] = timer;
				for (int j : adj2[i])
					dfs2(j, i);
				timer++;
				r[i] = timer;
			};
			dfs2(1, 1);
		}
		int lo = 1;
		int hi = n;
		ll skaicius = 0;
		vector<ll>cnt(n + 1, 0);
		vector<ll>F[2];
		const int mx = timer + 2;
		F[0] = F[1] = vector<ll>(mx, 0);
		auto addF = [&](int i, int c, int del)
		{
			while (i < mx)
			{
				F[c][i] += del;
				i += i & -i;
			}
		};
		auto getF = [&](int i, int c)
		{
			ll ret = 0;
			while (i > 0)
			{
				ret += F[c][i];
				i -= i & -i;
			}
			return ret;
		};
		map<int, int>M;
		int ans = 1;
		function<void(int, int)>dfs1 = [&](int i, int p)
		{
			bool prid = true;
			auto it = M.lower_bound(l[i]);
			if (it != M.end() && it->second <= r[i])
				prid = false;
			pair<int, int>v;
			bool reik = false;
			if (prid)
			{
				auto it = M.upper_bound(l[i]);
				if (it != M.begin())
				{
					it--;
					if (it->second >= l[i])
					{
						reik = true;
						v = *it;
						M.erase(it);
					}
				}
				M[l[i]] = r[i];
			}
			ans = max(ans, (int)M.size());
			for (int j : adj1[i])
				dfs1(j, i);
			if (prid)
			{
				M.erase(l[i]);
				if (reik)
				{
					M.insert(v);
				}
			}
		};
		dfs1(1, 1);
		cout << ans << "\n";
	}
}