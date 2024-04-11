/*input
3
5
abab
ab
abc
abacb
c
3
x
xx
xxx
8
codeforc
es
codes
cod
forc
forces
e
code

*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
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
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		set<string>K[9];
		for (int i = 0; i < n; i++)
			K[s[i].size()].insert(s[i]);
		string ans(n, '0');
		for (int i = 0; i < n; i++)
		{
			for (int a = 1; a < s[i].size(); a++)
			{
				string x = s[i].substr(0, a);
				string y = s[i].substr(a, s[i].size() - a);
				if (K[x.size()].count(x) != 0 && K[y.size()].count(y) != 0)
					ans[i] = '1';
			}
		}
		cout << ans << "\n";
	}
}