/*input
0
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll power(ll x, ll y)
{
	if (y == 0)
		return 1;
	if (y % 2 == 1)
		return (x * power(x, y - 1)) % modulo;
	ll z = power(x, y / 2);
	return (z * z) % modulo;
}
int main()
{
	ll n;
	cin >> n;
	if (n == 0)
	{
		cout << "1\n";
		return 0;
	}
	ll a = power(2, n - 1);
	ll b = power(2, n) + 1;
	a *= b;
	a %= modulo;
	cout << a << "\n";
	return 0;
}