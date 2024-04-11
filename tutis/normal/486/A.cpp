/*input
4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll ans = 1;
	ll n;
	cin >> n;
	if (n % 2 == 1)
		ans *= -1;
	ans *= (n + 1) / 2;
	cout << ans << "\n";
}