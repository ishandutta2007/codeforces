/*input
7
3
237
5
44444
3
221
2
35
3
773
1
4
30
626221626221626221626221626221
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
		int k;
		cin >> k;
		string s;
		cin >> s;
		set<char>C;
		int kiek = k + 1;
		int ans = -1;
		for (char c : s)
		{
			if (c == '1' || c == '4' || c == '6' || c == '8' || c == '9')
			{
				cout << 1 << "\n" << c << "\n";
				goto X;
			}
		}
		for (char c : s)
		{
			if (C.count(c))
			{
				cout << 2 << "\n" << c << c << "\n";
				goto X;
			}
			C.insert(c);
		}
		for (int msk = 1; msk < (1 << k); msk++)
		{
			int gal = 0;
			int cnt = 0;
			for (int i = 0; i < k; i++)
			{
				if ((msk & (1 << i)) != 0)
				{
					cnt++;
					gal = 10 * gal + (s[i] - '0');
				}
			}
			bool prime = true;
			for (int x = 2; x * x <= gal; x++)
				if (gal % x == 0)
					prime = false;
			if (!prime)
			{
				if (cnt <= kiek)
				{
					ans = gal;
					kiek = cnt;
				}
			}
		}
		cout << kiek << "\n" << ans << "\n";
X:;
	}
}