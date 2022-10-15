/*input
3
15 7 2
8 3 1
2 1 3

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
		int n, m, k;
		n = nxtInt();
		m = nxtInt();
		k = nxtInt();
		int cc[n + 1];
		int k0 = n / m;
		int k1 = k0 + 1;
		if (n % m == 0)
			k1--;
		int ccc = k * (k1) * (n / k1);
		for (int i = 1; i <= n; i++)
			cc[i] = 0;
		for (int i = 0; i < ccc; i++)
		{
			int a = i % n;
			cc[a + 1]++;
		}
		int id = 0;
		int c1, c0;
		for (int i = 0; i <= n; i++)
		{
			c0 = i;
			int l = n - c0 * k0;
			c1 = m - i;
			if (n == c0 * k0 + c1 * k1)
				break;
		}
		c1 *= k1;
		c0 *= k0;
		for (int c = 0; c < k; c++)
		{
			vector<int>x[2];
			int p[n];
			for (int i = 0; i < n; i++)
				p[i] = 0;
			for (int k = 0; k < c1; k++)
			{
				p[id] = 1;
				id = (id + 1) % n;
			}
			for (int i = 0; i < n; i++)
				if (p[i] == 1)
					x[1].push_back(i + 1);
				else
					x[0].push_back(i + 1);
			for (int i = 0; i < x[0].size(); i++)
			{
				if (i % k0 == 0)
					cout << k0;
				cout  << " " << x[0][i];
				if ((i + 1) % k0 == 0)
					cout << "\n";
			}
			for (int i = 0; i < x[1].size(); i++)
			{
				if (i % k1 == 0)
					cout << k1;
				cout  << " " << x[1][i];
				if ((i + 1) % k1 == 0)
					cout << "\n";
			}
		}
		cout << "\n";
	}
}