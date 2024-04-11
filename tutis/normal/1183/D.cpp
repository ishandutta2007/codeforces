/*input
3
8
1 4 8 4 5 6 3 8
16
2 1 3 3 4 3 4 4 1 3 2 2 2 4 1 1
9
2 2 4 4 4 7 7 7 7

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		int n;
		cin >> n;
		ll kiek[n];
		for (int i = 0; i < n; i++)
			kiek[i] = 0;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;
			kiek[a - 1]++;
		}
		sort(kiek, kiek + n, greater<ll>());
		ll ans = 0;
		ll xx = n + 10;
		for (int i = 0; i < n; i++)
		{
			ll x = max(0ll, min(xx, kiek[i]));
			ans += x;
			xx = x - 1;
		}
		cout << ans << "\n";
	}
}