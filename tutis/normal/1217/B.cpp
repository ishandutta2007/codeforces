/*input
3
3 10
6 3
8 2
1 4
4 10
4 1
3 2
2 6
1 100
2 15
10 11
14 100

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	while (T--)
	{
		ll n, x;
		cin >> n >> x;
		ll dm = -1;
		ll del = -1;
		while (n--)
		{
			ll d, h;
			cin >> d >> h;
			dm = max(dm, d);
			del = max(del, d - h);
		}
		if (x <= dm)
		{
			cout << "1\n";
			continue;
		}
		if (del <= 0)
		{
			cout << "-1\n";
			continue;
		}
		ll ans = 0;
		for (ll t = (1ll << 30); t > 0; t /= 2)
		{
			if (x - t * del > dm)
			{
				ans += t;
				x -= t * del;
			}
		}
		while (x != 0)
		{
			if (x <= dm)
			{
				ans++;
				x = 0;
				break;
			}
			else
			{
				ans++;
				x -= del;
			}
		}
		cout << ans << "\n";
	}
}