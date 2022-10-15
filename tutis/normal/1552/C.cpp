/*input
4
4 2
8 2
1 5
1 1
2 1
2 0
10 6
14 6
2 20
9 10
13 18
15 12
11 7

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
		int n, k;
		cin >> n >> k;
		vector<bool>yr(2 * n, true);
		int x[n], y[n];
		for (int i = 0; i < k; i++)
		{
			cin >> x[i] >> y[i];
			x[i]--;
			y[i]--;
			yr[x[i]] = false;
			yr[y[i]] = false;
		}
		vector<int>c;
		for (int i = 0; i < 2 * n; i++)
			if (yr[i] == true)
				c.push_back(i);
		for (int i = 0; i < c.size() / 2; i++)
		{
			int a = c[i];
			int b = c[i + c.size() / 2];
			x[k + i] = a;
			y[k + i] = b;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				int a = x[i];
				int b = y[i];
				int c = x[j];
				int d = y[j];
				int del = 2 * n - a;
				a += del;
				b += del;
				c += del;
				d += del;
				if (a >= 2 * n)
					a -= 2 * n;
				if (b >= 2 * n)
					b -= 2 * n;
				if (c >= 2 * n)
					c -= 2 * n;
				if (d >= 2 * n)
					d -= 2 * n;
				if (c < b && d < b)
					continue;
				if (c > b && d > b)
					continue;
				ans++;
			}
		}
		cout << ans << "\n";
	}
}