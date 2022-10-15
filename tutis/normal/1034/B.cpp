/*input
1 4

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	if (n > m)
		swap(n, m);
	ll ans = n * m;
	if (ans % 2 == 1)
		ans--;
	if (n - 1 + m - 1 < 3)
	{
		ans = 0;
	}
	else
	{
		if (n == 1)
		{
			if (m % 6 == 4)
				ans = (m / 6) * 6 + 2;
			else if (m % 6 == 5)
				ans = (m / 6) * 6 + 4;
			else
				ans = (m / 6) * 6;
		}
		if (n == 2)
		{
			if (m == 7 || m == 3)
				ans = n * m - 2;
		}
	}
	cout << ans << "\n";
}