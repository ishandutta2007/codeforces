/*input
6

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	cin >> n;
	int h = 0;
	int r = 2;
	while (r <= n)
	{
		h++;
		n -= r;
		r += 3;
	}
	if (n % 3 != 0)
	{
		h--;
		n += 2;
	}
	if (n % 3 != 0)
	{
		h--;
		n += 5;
	}
	ll ans = 0;
	for (ll i = h; i > 0; i -= 3)
		ans++;
	cout << ans << "\n";
	return 0;
}