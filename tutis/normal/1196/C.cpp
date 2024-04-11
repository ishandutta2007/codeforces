/*input
4
2
-1 -2 0 0 0 0
-1 -2 0 0 0 0
3
1 5 1 1 1 1
2 5 0 1 0 1
3 5 1 0 0 0
2
1337 1337 0 1 1 1
1336 1337 1 1 0 1
1
3 5 1 1 1 1

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
		ll x0 = -1e5;
		ll x1 = 1e5;
		ll y0 = -1e5;
		ll y1 = 1e5;
		int n;
		cin >> n;
		while (n--)
		{
			ll x, y;
			cin >> x >> y;
			ll f1, f2, f3, f4;
			cin >> f1 >> f2 >> f3 >> f4;
			ll x0_ = x, x1_ = x;
			ll y0_ = y, y1_ = y;
			if (f1)
				x0_ = -1e5;
			if (f2)
				y1_ = 1e5;
			if (f3)
				x1_ = 1e5;
			if (f4)
				y0_ = -1e5;
			x0 = max(x0, x0_);
			y0 = max(y0, y0_);
			x1 = min(x1, x1_);
			y1 = min(y1, y1_);
		}
		if (x0 <= x1 && y0 <= y1)
		{
			cout << 1 << " " << x0 << " " << y0 << "\n";
		}
		else
			cout << "0\n";
	}
}