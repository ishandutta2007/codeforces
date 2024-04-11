/*input
4
2
5 7
2
5 5
6
1 3 1 2 2 3
6
3 2 1 1 2 3

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
		vector<int>a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		map<int, int>cnt;
		for (int i = 0; i < n; i++)
			cnt[a[i]]++;
		bool ok = true;
		for (auto i : cnt)
			ok &= i.second % 2 == 0;
		if (!ok)
		{
			cout << "-1\n";
		}
		else
		{
			vector<pair<int, int>>ans;
			vector<int>ans1;
			int i0 = 0;
			while (i0 < a.size())
			{
				int i1 = i0 + 1;
				while (a[i1] != a[i0])
					i1++;
				int sz = i1 - i0;
				for (int i = i0; i < i0 + sz; i++)
				{
					if (i + sz >= a.size() || a[i] != a[i + sz])
					{
						a.insert(a.begin() + (i + sz), a[i]);
						a.insert(a.begin() + (i + sz), a[i]);
						ans.push_back({i + sz, a[i]});
					}
				}
				ans1.push_back(sz);
				i0 += sz * 2;
				sz = (a.size() - i0);
			}
			cout << ans.size() << "\n";
			for (auto i : ans)
				cout << i.first << " " << i.second << "\n";
			cout << ans1.size() << "\n";
			for (auto i : ans1)
				cout << i * 2 << "\n";
		}
	}
}