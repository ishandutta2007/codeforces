/*input
4
1 3
6 12
2 1
3 6

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
mt19937 rng(0);
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		if (m < n)
			cout << "No\n";
		else
		{
			if (n % 2 == 1)
			{
				cout << "Yes\n";
				for (int i = 0; i < n - 1; i++)
					cout << "1 ";
				cout << m - (n - 1) << "\n";
			}
			else
			{
				if (m % 2 == 1)
				{
					cout << "No\n";
				}
				else
				{
					cout << "Yes\n";
					for (int i = 0; i < n - 2; i++)
						cout << "1 ";
					cout << (m - (n - 2)) / 2 << " ";
					cout << (m - (n - 2)) / 2 << "\n";
				}
			}
		}
	}
	return 0;
}