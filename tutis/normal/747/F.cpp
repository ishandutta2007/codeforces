/*input
1000000 2
*/
#pragma GCC optimize ("O3")
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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(1234);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
char C[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
ll Ch[100][100];
ll f(vector<int>cnt, int len)
{
	if (len == 0)
		return 1;
	for (int t = 0; t < 16; t++)
	{
		if (cnt[t] > 0)
		{
			int c = cnt[t];
			ll ret = 0;
			cnt[t] = 0;
			for (int k = 0; k <= min(len, c); k++)
			{
				ret += f(cnt, len - k) * Ch[len][k];
				if (ret >= 2000000000)
					return ret;
			}
			return ret;
		}
	}
	return 0;
}
string f(vector<int>cnt, int len, ll n)
{
	if (len == 0)
		return "";
	for (int t = 0; t < 16; t++)
	{
		if (cnt[t] > 0)
		{
			cnt[t]--;
			ll k = f(cnt, len - 1);
			if (n > k)
				n -= k;
			else
			{
				string ret = f(cnt, len - 1, n);
				ret.insert(ret.begin(), C[t]);
				return ret;
			}
			cnt[t]++;
		}
	}
}
int main()
{
	for (int n = 0; n < 100; n++)
	{
		for (int k = 0; k < 100; k++)
		{
			if (k > n)
				Ch[n][k] = 0;
			else
			{
				if (k == 0 || k == n)
					Ch[n][k] = 1;
				else
					Ch[n][k] = Ch[n - 1][k] + Ch[n - 1][k - 1];
				Ch[n][k] = min(Ch[n][k], 2000000000ll);
			}
		}
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k, t;
	cin >> k >> t;
	for (int l = 1;; l++)
	{
		for (int d0 = 1; d0 <= 15; d0++)
		{
			vector<int>cnt(16, t);
			cnt[d0]--;
			int kiek = f(cnt, l - 1);
			if (k <= kiek)
			{
				cout << C[d0] << f(cnt, l - 1, k) << "\n";
				return 0;
			}
			else
				k -= kiek;
		}
	}
}