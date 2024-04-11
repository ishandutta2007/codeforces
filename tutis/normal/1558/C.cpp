/*input
3
3
1 2 3
5
3 4 5 2 1
3
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
		int n;
		cin >> n;
		int a[n + 2];
		a[n + 1] = 0;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		bool ok = true;
		for (int i = 1; i <= n; i++)
			if ((a[i] % 2) != (i % 2))
				ok = false;
		if (!ok)
		{
			cout << "-1\n";
		}
		else
		{
			vector<int>ans;
			auto flip = [&](int k)
			{
				if (k == 1)
					return;
				reverse(a + 1, a + k + 1);
				ans.push_back(k);
			};
			for (int x = 2; x <= n; x++)
				if (a[x] == 1)
				{
					flip(x);
					break;
				}
			for (int v = 3; v <= n; v += 2)
			{
				int s1 = v - 2;
				int s2 = v - 1;
				int s3 = v;
				int s0 = s1 - 1;
				{
					int i = 1;
					while (a[i] != s2)
						i++;
					flip(i - 1);
					flip(i + 1);
					flip(3);
					i = 1;
					while (a[i] != s0)
						i++;
					flip(i - 1);
					i = 1;
					while (a[i] != s3)
						i++;
					flip(i);
				}
			}
			flip(n);
			cout << ans.size() << "\n";
			for (int i : ans)
				cout << i << " ";
			cout << "\n";
		}
	}



}