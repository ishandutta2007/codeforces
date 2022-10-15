/*input
13 3
3 2 7
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll b, k;
	cin >> b >> k;
	vector<ll>a(k);
	for (ll&i : a)
		cin >> i;
	reverse(a.begin(), a.end());
	ll r = 0;
	ll x = 1;
	for (ll i : a)
	{
		r += i * x;
		i %= 2;
		x %= 2;
		r %= 2;
		b %= 2;
		x *= b;
	}
	if (r % 2 == 0)
		cout << "even\n";
	else
		cout << "odd\n";
}