/*input
46
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll sum(ll x)
{
	if (x == 0)
		return 0;
	if (x % 10 == 9)
	{
		return 45 * (x + 1) / 10 + 10 * sum(x / 10);
	}
	ll ret = sum(x - 1);
	while (x != 0)
	{
		ret += x % 10;
		x /= 10;
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll a;
	cin >> a;
	while (true)
	{
		ll l = uniform_int_distribution<ll>(0, 5e16)(rng);
		ll lo = l + 1;
		ll hi = l + 5e16;
		while (lo < hi)
		{
			ll r = (lo + hi) / 2;
			ll v = sum(r) - sum(l);
			if (v % a == 0)
			{
				cout << l + 1 << " " << r << endl;
				return 0;
			}
			if (v > a)
				hi = r - 1;
			else
				lo = r + 1;
		}
	}

}