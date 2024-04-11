/*input
4
1
()
3
()(())
3
((()))
4
(())(())
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(0);
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
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
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
		string s;
		cin >> s;
		int ss[2 * n + 1];
		ss[0] = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			ss[i + 1] = ss[i];
			if (s[i] == '(')
				ss[i + 1]++;
			if (s[i] == ')')
				ss[i + 1]--;
		}
		map<int, vector<int>>M;
		for (int i = 0; i <= 2 * n; i++)
			M[ss[i]].push_back(i);
		int pa[2 * n + 1];
		for (int i = 0; i <= 2 * n; i++)
			pa[i] = i;
		function<int(int)>root = [&](int x)
		{
			if (x == pa[x])
				return x;
			return pa[x] = root(pa[x]);
		};
		auto merge = [&](int x, int y)
		{
			x = root(x);
			y = root(y);
			pa[x] = y;
		};
		function<void(int, int)>f = [&](int l, int r)
		{
			if (l > r)
				return;
			merge(l, r);
			int m = *upper_bound(M[ss[l - 1]].begin(), M[ss[l - 1]].end(), l);
			f(l + 1, m - 1);
			merge(l, m);
			f(m + 1, r);
		};
		f(1, 2 * n);
		int ret = 0;
		for (int i = 1; i <= 2 * n; i++)
			if (pa[i] == i)
				ret++;
		cout << ret << "\n";
	}
	return 0;
}