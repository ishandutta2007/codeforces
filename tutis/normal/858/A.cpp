/*input
375 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll x = 1;
	while (k--)
		x *= 10;
	cout << x*n / __gcd(x, n) << "\n";
}