/*input
3 6 3
1
2
1
3
1
3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll n, m, c;
	cin >> n >> m >> c;
	ll a[n + 2];
	ll b[n + 2];
	fill_n(a, n + 2, (ll)1e6);
	fill_n(b, n + 2, -2);
	ll x;
	while (cin >> x)
	{
		int i1 = 1;
		int i2 = n;
		while (a[i1] <= x)
			i1++;
		while (b[i2] >= x)
			i2--;
		int i = i2;
		if (x * 2 <= c)
		{
			i = i1;
		}
		else
		{
			i = i2;
		}
		cout << i << endl;
		if (i == i2)
		{
			b[i] = x;
		}
		if (i == i1)
		{
			a[i] = x;
		}
	}
}