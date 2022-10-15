/*input
6 9
0 4 5 0
1 5
1 6
0 4 6 1
1 6
0 2 5 1
0 2 2 0
1 3
1 2

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
	int n, q;
	cin >> n >> q;
	set<int>mayb;
	for (int i = 1; i <= n; i++)
		mayb.insert(i);
	map<int, int>I;
	map<int, int, greater<int>>J;
	while (q--)
	{
		int t;
		cin >> t;
		if (t == 0)
		{
			int l, r, x;
			cin >> l >> r >> x;
			if (x == 0)
			{
				auto it = mayb.lower_bound(l);
				while (it != mayb.end() && (*it) <= r)
				{
					it = mayb.erase(it);
				}
			}
			else
			{
				bool ok = true;
				auto it = I.lower_bound(l);
				if (it != I.end() && it->second <= r)
					ok = false;
				if (ok)
				{
					while (true)
					{
						auto it = I.lower_bound(l + 1);
						if (it != I.begin())
						{
							it--;
							if (it->second >= r)
							{
								J.erase(it->second);
								I.erase(it);
							}
							else
								break;
						}
						else
							break;
					}
					I[l] = r;
					J[r] = l;
				}
			}
		}
		else
		{
			int j;
			cin >> j;
			auto itt = mayb.find(j);
			if (itt != mayb.end())
			{
				int x0 = -1;
				int x1 = n + 1;
				{
					auto it = itt;
					it++;
					if (it != mayb.end())
						x1 = *it;
				}
				{
					auto it = itt;
					if (it != mayb.begin())
					{
						it--;
						x0 = *it;
					}
				}
				bool yra = false;
				{
					vector<pair<int, int>>check;
					{
						auto it = I.lower_bound(x0 + 1);
						if (it != I.end())
							check.push_back({it->first, it->second});
						it = I.lower_bound(j + 1);
						if (it != I.begin())
						{
							it--;
							check.push_back({it->first, it->second});
						}
					}
					{
						auto it = J.lower_bound(x1 - 1);
						if (it != J.end())
							check.push_back({it->second, it->first});
						it = I.lower_bound(j - 1);
						if (it != I.begin())
						{
							it--;
							check.push_back({it->second, it->first});
						}
					}
					for (auto i : check)
					{
						if (i.first <= j && j <= i.second && x0 < i.first && i.second < x1)
							yra = true;
					}
				}
				if (yra)
					cout << "YES\n";
				else
					cout << "N/A\n";
			}
			else
			{
				cout << "NO\n";
			}
		}
	}
}