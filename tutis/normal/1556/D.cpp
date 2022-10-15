/*input
7 6
7
6
5
0
4
0
0
0
0
0
0
0
0
0
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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	auto get = [&](int l, int r)->int
	{
		cout << "or " << l << " " << r << endl;
		cout << "and " << l << " " << r << endl;
		int x, y;
		cin >> x >> y;
		return x - y;
	};
	auto geto = [&](int l, int r)->int
	{
		cout << "or " << l << " " << r << endl;
		int x;
		cin >> x;
		return x;
	};
	auto geta = [&](int l, int r)->int
	{
		cout << "and " << l << " " << r << endl;
		int x;
		cin >> x;
		return x;
	};
	int o12 = geto(1, 2);
	int o23 = geto(2, 3);
	int o31 = geto(1, 3);
	int a12 = geta(1, 2);
	int a23 = geta(2, 3);
	int a31 = geta(1, 3);
	int mass[6] = {o12, o23, o31, a12, a23, a31};
	int sk1 = 0;
	for (int bit = 1; bit < (1 << 30); bit *= 2)
	{
		for (int x1 : {0, bit})
		{
			for (int x2 : {0, bit})
			{
				for (int x3 : {0, bit})
				{
					int mas[6] = {x1 | x2, x2 | x3, x3 | x1,
					              x1 & x2, x2 & x3, x3 & x1,
					             };
					bool ok = true;
					for (int i = 0; i < 6; i++)
					{
						int xx = mas[i] & bit;
						int yy = mass[i] & bit;
						if (xx != yy)
							ok = false;
					}
					if (ok)
						sk1 |= x1;
				}
			}
		}
	}
	int ans[n + 1];
	ans[1] = sk1;
	ans[2] = sk1 ^ (o12 - a12);
	ans[3] = ans[2] ^ (o23 - a23);
	for (int i = 4; i <= n; i++)
	{
		ans[i] = ans[i - 1] ^ get(i - 1, i);
	}
	sort(ans + 1, ans + n + 1);
	cout << "finish " << ans[k] << endl;
}