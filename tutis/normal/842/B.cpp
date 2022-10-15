/***
10 8
4
0 0 9
0 0 10
1 0 1
1 0 2
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll r, d;
	cin >> r >> d;
	ll n;
	cin >> n;
	ll ans = 0;
	int i = 0;
	while (n--)
	{
		i++;
		ll x, y, ri;
		cin >> x >> y >> ri;
		if (x * x + y * y <= r * r)
			if ((x * x + y * y) <= (r - ri) * (r - ri) && ri <= r)
			{
				if ((x * x + y * y) >= (r - d + ri) * (r - d + ri))
					if (x * x + y * y >= (r - d) * (r - d))
					{
						//cout << i << endl;
						ans++;
					}
			}
	}
	cout << ans;
}