/*input
64
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
pair<ll, ll>f(ll n)
{
	if (n % 2 == 1)
	{
		ll x = (n * n - 1) / 2;
		return {x, x + 1};
	}
	if (n % 4 == 0)
	{
		return {n / 4 * 3, n / 4 * 5};
	}
	if (n % 2 == 0)
	{
		pair<ll, ll>x = f(n / 2);
		x.first *= 2;
		x.second *= 2;
		return x;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if (n <= 2)
	{
		cout << "-1\n";
		return 0;
	}
	cout << f(n).first << " " << f(n).second << "\n";
}