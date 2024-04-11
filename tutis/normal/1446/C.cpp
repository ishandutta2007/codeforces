/*input
7
6 9 8 7 3 5 2

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
	int n;
	cin >> n;
	vector<int>a(n);
	for (int &i : a)
		cin >> i;
	function<int(vector<int>, int)>f = [&](vector<int>a, int d)->int
	{
		if (a.size() <= 1)
			return a.size();
		vector<int>v[2];
		for (int i : a)
		{
			if ((i & (1 << d)) != 0)
				v[0].push_back(i);
			else
				v[1].push_back(i);
		}
		int x[2] = {f(v[0], d - 1), f(v[1], d - 1)};
		int ret = max(x[0], x[1]);
		if (!v[0].empty())
			ret = max(ret, x[1] + 1);
		if (!v[1].empty())
			ret = max(ret, x[0] + 1);
		return ret;
	};
	cout << n - f(a, 29) << "\n";
}