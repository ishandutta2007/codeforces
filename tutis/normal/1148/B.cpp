/*input
4 3 2 3 1
1 999999998 999999999 1000000000
3 4 1000000000

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	deque<ll>a(n);
	deque<ll>b(m);
	for (ll &i : a)
	{
		cin >> i;
		i += ta;
		i += tb;
	}
	for (ll &i : b)
	{
		cin >> i;
		i += tb;
	}
	ll ans = -1;
	ll buvo = ans;
	if (k >= a.size() || k >= a.size())
	{
		cout << "-1\n";
		return 0;
	}
	while (true)
	{
		if (k >= b.size())
		{
			cout << "-1\n";
			return 0;
		}
		ans = max(ans, b[k]);
		if (b[0] < a[0])
		{
			b.pop_front();
			continue;
		}
		if (k > 0)
		{
			a.pop_front();
			k--;
			continue;
		}
		break;
	}
	cout << ans << "\n";
}