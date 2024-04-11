/*input
2
3
4
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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			a[i] = i;
		while (true)
		{
			int id[3] = {n, (int)(rng() % (n - 1) + 1), 1};
			if (id[2] == id[1])
				continue;
			int cnt = 8;
			bool ok = true;
			vector<pair<int, int>>ans;
			for (int i = 0; i < cnt; i++)
			{
				sort(id, id + 3, [&](int x, int y) {return a[x] < a[y];});
				a[id[2]] = (a[id[2]] - 1) / a[id[1]] + 1;
				ans.push_back({id[2], id[1]});
			}
			sort(id, id + 3, [&](int x, int y) {return a[x] < a[y];});
			if (a[id[2]] == 2 && a[id[1]] == 1 && a[id[0]] == 1) {
				vector<pair<int, int>>ans1;
				for (int i = 1; i <= n; i++)
				{
					if (i != id[0] && i != id[1] && i != id[2])
					{
						ans1.push_back({i, n});
					}
				}
				for (auto a : ans)
					ans1.push_back(a);
				cout << ans1.size() << "\n";
				for (auto i : ans1)
					cout << i.first << " " << i.second << "\n";
				break;
			}
			for (int i : id)
				a[i] = i;
		}
	}

}