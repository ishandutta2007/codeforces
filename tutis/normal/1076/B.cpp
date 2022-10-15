/*input
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll answer(ll n)
{
	if (n == 0)
		return 0;
	if (n % 2 == 0)
		return n / 2;
	for (ll i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return 1 + answer(n - i);
	}
	return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	cout << answer(n) << "\n";
}