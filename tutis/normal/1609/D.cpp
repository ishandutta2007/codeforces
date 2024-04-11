/*input
7 6
1 2
3 4
2 4
7 6
6 5
1 7

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
mt19937_64 rng(0);
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
	cin.tie(0);
	int n, d;
	cin >> n >> d;
	int sz[n + 1];
	int pa[n + 1];
	for (int i = 1; i <= n; i++)
	{
		sz[i] = 1;
		pa[i] = i;
	}
	function<int(int)>root = [&](int x)
	{
		if (pa[x] == x)
			return x;
		return pa[x] = root(pa[x]);
	};
	int ans = 1;
	int cnt = 1;
	multiset<int>A;
	multiset<int>B;
	for (int i = 1; i < n; i++)
		A.insert(sz[i]);
	B.insert(sz[1]);
	auto add = [&](int x)
	{
		if (x > (*B.begin()))
		{
			int y = *B.begin();
			B.erase(B.begin());
			A.insert(y);
			B.insert(x);
			ans += x - y;
		}
		else
		{
			A.insert(x);
		}
	};
	auto rem = [&](int x)
	{
		if (A.find(x) != A.end())
		{
			A.erase(A.find(x));
		}
		else
		{
			B.erase(B.find(x));
			ans -= x;
			if (A.size() > 0)
			{
				auto it = --A.end();
				B.insert(*it);
				ans += *it;
				A.erase(it);
			}
		}
	};
	while (d--)
	{
		int x, y;
		cin >> x >> y;
		x = root(x);
		y = root(y);
		if (x != y)
		{
			add(sz[x] + sz[y]);
			rem(sz[x]);
			rem(sz[y]);
			pa[x] = y;
			sz[y] += sz[x];
			ans = max(ans, sz[y]);
		}
		else
		{
			cnt++;
			if (A.size() > 0)
			{
				auto it = --A.end();
				B.insert(*it);
				ans += *it;
				A.erase(it);
			}
		}
		cout << ans - 1 << "\n";
	}
}