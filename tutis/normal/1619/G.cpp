/*input
3

5 0
0 0 1
0 1 4
1 0 2
1 1 3
2 2 9

5 2
0 0 1
0 1 4
1 0 2
1 1 3
2 2 9

6 1
1 -1 3
0 -1 9
0 1 7
-1 0 1
-1 1 9
-1 -1 7

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
int nxtInt()
{
	int c = getchar();
	while (c != '-' && (c < '0' || c > '9'))
		c = getchar();
	int x = 0;
	bool neg = false;
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	if (neg)
		return -x;
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	t = nxtInt();
	while (t--)
	{
		int n, k;
		n = nxtInt();
		k = nxtInt();
		map<int, set<pair<int, int>>>X, Y;
		int x[n], y[n], t[n], p[n];
		for (int i = 0; i < n; i++)
		{
			x[i] = nxtInt();
			y[i] = nxtInt();
			t[i] = nxtInt();
			p[i] = i;
			X[x[i]].insert({y[i], i});
			Y[y[i]].insert({x[i], i});
		}
		function<int(int)>root = [&](int x)
		{
			if (x == p[x])
				return x;
			return p[x] = root(p[x]);
		};
		auto merge = [&](int a, int b)
		{
			p[root(a)] = root(b);
		};
		for (int i = 0; i < n; i++)
		{
			auto it = X[x[i]].lower_bound({y[i] + 1, -1});
			if (it != X[x[i]].end())
			{
				pair<int, int>c = *it;
				if (c.first <= y[i] + k)
					merge(c.second, i);
			}
			it = Y[y[i]].lower_bound({x[i] + 1, -1});
			if (it != Y[y[i]].end())
			{
				pair<int, int>c = *it;
				if (c.first <= x[i] + k)
					merge(c.second, i);
			}
		}
		for (int i = 0; i < n; i++)
			t[root(i)] = min(t[root(i)], t[i]);
		vector<int>T;
		for (int i = 0; i < n; i++)
			if (p[i] == i)
				T.push_back(t[i]);
		sort(T.begin(), T.end(), greater<int>());
		int ans = T.size() - 1;
		for (int i = 0; i < T.size(); i++)
		{
			ans = min(ans, max(i - 1, T[i]));
		}
		cout << ans << "\n";
	}
}