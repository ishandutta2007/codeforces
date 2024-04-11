/***
1 5 6 10 1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for (ll a = l; a <= r; a++)
	{
		ll b = a / k;
		if (b != 0 && a % b == 0 && a / b == k && x <= b && b <= y)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
}