/*input
5

2 2
1 2
3 4

4 3
1 3 1
3 1 1
1 2 2
1 1 3

2 3
5 3 4
2 5 1

4 2
7 9
8 1
9 6
10 8

2 4
6 5 2 1
7 9 7 2
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
	char c = getchar();
	while (c < '0' || c > '9')
		c = getchar();
	int x = 0;
	while (c >= '0' && c <= '9')
	{
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t = nxtInt();
	while (t--)
	{
		int m = nxtInt();
		int n = nxtInt();
		int p[m][n];
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				p[i][j] = nxtInt();
		int lo = 0;
		int hi = 1000000000;
		while (lo < hi)
		{
			int a = (lo + hi + 1) / 2;
			bool ok = true;
			for (int i = 0; i < n; i++)
			{
				bool ger = false;
				for (int j = 0; j < m; j++)
					if (p[j][i] >= a)
						ger = true;
				ok &= ger;
			}
			if (m >= n)
			{
				bool ger = false;
				for (int j = 0; j < m; j++)
				{
					int c = 0;
					for (int i = 0; i < n; i++)
						if (p[j][i] >= a)
							c++;
					if (c >= 2)
						ger = true;
				}
				ok &= ger;
			}
			if (ok)
				lo = a;
			else
				hi = a - 1;
		}
		cout << lo << "\n";
	}
}