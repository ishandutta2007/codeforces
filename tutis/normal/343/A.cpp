/*input
1 1
3 2
199 200
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll ans(ll a, ll b)
{
	if (a == 0)
		return 0;
	if (b == 0)
		return 0;
	if (a % b == 0)
		return a / b;
	if (a >= b)
		return a / b + ans(a % b, b);
	return b / a + ans(a, b % a);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a, b;
	while (cin >> a >> b)
	{
		cout << ans(a, b) << endl;
	}
}