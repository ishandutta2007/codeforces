/*input
2 4

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353;
ll f(ll n)
{
	if (n == 1)
		return 4;
	return (2 * f(n - 1)) % modulo;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll w, h;
	cin >> w >> h;
	cout << f(w + h - 1) << "\n";
}