/*input
5
3
0 1 3
7
0 1 2 3 4 3 2
4
3 0 0 0
7
4 6 2 3 5 0 5
5
4 0 1 0 4

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
		int n = nxtInt();
		int a[n];
		for (int i = 0; i < n; i++)
			a[i] = nxtInt();
		sort(a, a + n);
		ll cost[n + 1];
		for (int i = 0; i <= n; i++)
			cost[i] = 0;
		for (int v : a)
			cost[v]++;
		ll sum = 0;
		bool ok = true;
		multiset<int, greater<int>>S;
		for (int v : a)
			S.insert(v);
		for (int i = 0; i < n; i++)
		{
			auto it = S.lower_bound(i);
			if (it != S.end())
			{
				sum += i - (*it);
				S.erase(it);
			}
			else
				ok = false;
			if (ok)
				cost[i + 1] += sum;
			else
				cost[i + 1] = -1;
		}
		for (int i = 0; i <= n; i++)
			cout << cost[i] << " ";
		cout << "\n";
	}
}