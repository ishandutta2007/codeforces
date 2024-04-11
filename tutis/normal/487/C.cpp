/*input
6
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
mt19937_64 rng(123);
const ll mod = 1000000007;
array<int, 26>A[100000];
void egcd(ll a, ll b, ll &x, ll &y, ll d)
{	//ax+by=d
	if (a == 0)
	{
		x = 0;
		y = d / b;
	}
	else if (b == 0)
	{
		y = 0;
		x = d / a;
	}
	else
	{
		if (a > b)
			egcd(b, a, y, x, d);
		else
		{
			ll k = b / a;
			ll l = b % a;
			//ax + (k * a + l)y = d;
			//a(x+ky) + ly = d;
			egcd(a, l, x, y, d);
			x -= k * y;
		}
	}
}
int inv(int x, int m)
{
	//xa+mb=1
	ll a, b;
	egcd(x, m, a, b, 1);
	a %= m;
	if (a < 0)
		a += m;
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	if (n <= 3)
	{
		cout << "YES\n";
		int s = 1;
		for (int i = 1; i <= n; i++)
			cout << i << " ";
		return 0;
	}
	for (int x = 2; x * x < n; x++)
	{
		if (n % x == 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	int x = 2;
	while (x * x < n)
		x++;
	if (x * x == n)
	{
		cout << "YES\n";
		cout << 1 << " ";
		ll s = 1;
		for (int i = 2; i < n; i++)
		{
			if (i != x)
			{
				cout << (i * inv(s, n)) % n << " ";
				s = i;
			}
		}
		cout << x << " " << n << "\n";
	}
	else
	{
		cout << "YES\n";
		cout << 1 << " ";
		for (int i = 2; i < n; i++)
		{
			cout << 1 + inv(i - 1, n) << " ";
		}
		cout << n << "\n";
	}
}