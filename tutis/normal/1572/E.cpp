/*input
8 4
-2 -4
2 -2
4 2
1 5
0 5
-4 4
-5 0
-5 -1

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
struct point
{
	ll x, y;
	point()
	{
		x = y = 0;
	}
	point (ll a, ll b): x(a), y(b)
	{

	}
};
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
ll area(const point &a, const point &b, const point &c)
{
	return abs(cross(b - a, c - a));
}
pair<int, ll> dp[203][203];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	point A[n];
	for (int i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y;
	ll lo = 1;
	ll hi = 8e16 + 10;
	auto check = [&](ll x)->bool
	{
		for (int sz = 2; sz <= n; sz++)
		{
			for (int i = 0; i + sz - 1 < n; i++)
			{
				int j = i + sz - 1;
				dp[i][j] = {0, -1e17};
				if (sz == 2)
					dp[i][j] = {0, 0};
				for (int id = i + 1; id < j; id++)
				{
					ll ar = area(A[i], A[id], A[j]);
					pair<int, ll> s1 = dp[i][id];
					pair<int, ll> s2 = dp[id][j];
					int c = s1.first + s2.first;
					ll area = s1.second + s2.second + ar;
					if (area >= x)
					{
						area = 0;
						c++;
					}
					dp[i][j] = max(dp[i][j], {c, area});
				}
			}
		}
		return dp[0][n - 1].first >= k + 1;
	};
	while (lo < hi)
	{
		ll x = (lo + hi + 1) / 2;
		if (check(x))
			lo = x;
		else
			hi = x - 1;
	}
	cout << lo << "\n";
}