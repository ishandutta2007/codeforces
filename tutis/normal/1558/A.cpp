/*input
3
2 1
1 1
0 5

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
		int a, b;
		cin >> a >> b;
		vector<int>ans;
		for (int k = 0; k <= a + b; k++)
		{

		}
		for (int c : {0, 1})
		{
			if (c == 1 && ((a + b) % 2) == 0)
				continue;
			int x = (a + b) / 2 + c;
			int y = a + b - x;
			for (int v = 0; v <= y && v <= a; v++)
			{
				int v_ = a - v;
				int w = x - v_;
				int w_ = b - w;
				if (w >= 0 && w <= b)
				{
					ans.push_back(v + w);
				}
			}
		}
		sort_unique(ans);
		cout << ans.size() << "\n";
		for (int i : ans)
			cout << i << " ";
		cout << "\n";
	}
}