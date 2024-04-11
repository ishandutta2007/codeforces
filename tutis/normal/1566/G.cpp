/*input
6 6
1 3 6
4 3 1
1 4 1
2 6 4
2 4 2
5 4 3
4
1 2 5 2
0 1 4
0 3 4
1 6 1 3

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
using uint = unsigned int;
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
	int n, m;
	cin >> n >> m;
	map<int, pair<int, int>>ww[n + 1];
	while (m--)
	{
		int a, b, w;
		cin >> a >> b >> w;
		if (a > b)
			swap(a, b);
		ww[a][b] = {w, 0};
	}
	int q;
	cin >> q;
	vector<pair<pair<int, int>, pair<pair<int, int>, int>>>E;
	for (int t = 1; t <= q; t++)
	{
		int tip;
		cin >> tip;
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (tip == 0)
		{
			pair<pair<int, int>, pair<pair<int, int>, int>>x = {{ww[a][b].second, t - 1}, {{a, b}, ww[a][b].first}};
			E.push_back(x);
			ww[a].erase(b);
		}
		else
		{
			int w;
			cin >> w;
			ww[a][b] = {w, t};
		}
	}
	for (int a = 1; a <= n; a++)
	{
		for (pair<int, pair<int, int>> i : ww[a])
		{
			pair<pair<int, int>, pair<pair<int, int>, int>>x = {{i.second.second, q}, {{a, i.first}, i.second.first}};
			E.push_back(x);
		}
		ww[a].clear();
	}
	ordered_set<pair<int, int>> edg[n + 1];
	ordered_set<pair<int, pair<int, int>>>edd;
	function<void(int, int, uint, vector<pair<pair<int, int>, pair<pair<int, int>, int>>>)>search =
	    [&](int t0, int t1, uint mn, vector<pair<pair<int, int>, pair<pair<int, int>, int>>>E)->void
	{
		vector<pair<pair<int, int>, pair<pair<int, int>, int>>>E_;
		vector<pair<pair<int, int>, int>>rem;
		for (auto i : E)
		{
			int x0 = i.first.first;
			int x1 = i.first.second;
			if (x0 <= t0 && t1 <= x1)
			{
				pair<pair<int, int>, int>e = i.second;
				rem.push_back(e);
				for (int a : {e.first.first, e.first.second})
				{
					if (edg[a].size() >= 2)
					{
						auto it = edg[a].begin();
						uint val0 = it->first;
						it++;
						uint val1 = it->first;
						uint val2 = e.second;
						mn = min(mn, {val0 + val1 + val2});
					}
				}
				int hi = min((uint)2e9 + 100, mn) - e.second;
				int lo = 1;
				if (lo <= hi)
				{
					auto test = [&](int k)->bool
					{
						int cnt1 = edg[e.first.first].order_of_key({k, (int)1e6});
						int cnt2 = edg[e.first.second].order_of_key({k, (int)1e6});
						int cnt3 = edd.order_of_key({k, {(int)1e6, (int)1e6}});
						if (cnt3 - cnt2 - cnt1 > 0)
							return true;
						else
							return false;
					};
					if (test(hi))
					{
						for (auto i : edd)
						{
							if (i.first > hi)
								break;
							if (i.second.first == e.first.first)
								continue;
							if (i.second.first == e.first.second)
								continue;
							if (i.second.second == e.first.first)
								continue;
							if (i.second.second == e.first.second)
								continue;
							mn = e.second + i.first;
							break;
						}
						// while (lo < hi)
						// {
						// 	int m = (lo + hi) / 2;
						// 	if (test(m))
						// 		hi = m;
						// 	else
						// 		lo = m + 1;
						// }
						//mn = e.second + lo;
					}
				}
				edd.insert({e.second, e.first});
				edg[e.first.first].insert({e.second, e.first.second});
				edg[e.first.second].insert({e.second, e.first.first});
			}
			else if (t1 < x0 || x1 < t0)
				continue;
			else
			{
				E_.push_back(i);
			}
		}
		E.clear();
		if (t0 == t1)
		{
			cout << mn << "\n";
		}
		else
		{
			search(t0, (t0 + t1) / 2, mn, E_);
			search((t0 + t1) / 2 + 1, t1, mn, E_);
		}
		for (pair<pair<int, int>, int>e : rem)
		{
			edd.erase({e.second, e.first});
			edg[e.first.first].erase({e.second, e.first.second});
			edg[e.first.second].erase({e.second, e.first.first});
		}
	};
	search(0, q, 4e9, E);
}