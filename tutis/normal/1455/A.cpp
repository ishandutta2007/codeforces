/*input
5
4
37
998244353
1000000007
12345678901337426966631415

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
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
bool prime(int x)
{
	if (x <= 1)
		return false;
	for (int a = 2; a * a <= x; a++)
	{
		if (x % a == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int>P;
	while (P.size() < 4)
	{
		int x = rng() % 1000000000;
		if (prime(x) && x >= 10000000)
		{
			P.push_back(x);
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		cout << s.size() << "\n";
	}

}