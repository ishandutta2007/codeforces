/*input
5
7
1 2
1 3
1 4
2 5
2 6
4 7
6
1 2
1 3
2 4
2 5
3 6
2
1 2
7
7 3
1 5
1 3
4 6
4 7
2 1
6
2 1
2 3
4 5
3 4
3 6
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
		vector<int>adj[n + 1];
		for (int i = 1; i < n; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int>x;
		function<int(int, int)>dfs = [&](int i, int p)->int
		{
			int ans = 1;
			int cnt = 0;
			for (int j : adj[i])
				if (j != p)
				{
					int s = dfs(j, i);
					if (s == 1)
					{
						cnt++;
						ans = 0;
					}
				}
			if (ans == 1)
			{
				if (p == 1)
					x.push_back(0);
			}
			else
				x.push_back(cnt);
			return ans;
		};
		dfs(1, 1);
		int ret = 0;
		sort(x.begin(), x.end(), greater<int>());
		if (x.size() == adj[1].size())
			ret = x.size();
		else
		{
			for (int s : x)
			{
				if (ret == 0)
					ret = s;
				else
				{
					if (s != 0)
					{
						ret--;
						ret += s;
					}
				}
			}
		}
		cout << ret << "\n";
	}
}