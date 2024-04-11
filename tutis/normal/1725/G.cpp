/*input
1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
const ll mod = 1e9 + 7;
ll p(ll x, ll y)
{
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N;
	cin >> N;
	ll lo = 2;
	ll hi = 1e12;
	while (lo < hi)
	{
		ll m = (lo + hi) / 2;
		ll c = m - ((m / 2) - (m / 4)) - 1;
		if (m >= 4)
			c--;
		if (c >= N)
			hi = m;
		else
			lo = m + 1;
	}
	cout << lo << "\n";
	for (int b = 2; b <= 100; b++)
	{
		for (int a = 1; a < b; a++)
		{
			int c = b * b - a * a;
			//(b-a)(b+a)
			//x(x+y)
			//x^2+xy
			//
		}
	}
	return 0;
}