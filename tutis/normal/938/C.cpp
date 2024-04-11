/***
3
21
0
1
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Sqr(ll a)
{
	return round(sqrt(a));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int x;
		cin >> x;
		bool ok = false;
		for (ll n = 1; n * n <= 2000000000; n++)
		{
			ll a = n * n - x;
			if (a < 0)
				continue;
			if (Sqr(a)*Sqr(a) == a)
			{
				ll b = Sqr(a);
				if (b == 0)
					continue;
				ll m = n / b;
				if (m == 0)
					continue;
				while (m != 0 && n / m < b)
					m--;
				while (m != 0 && n / m > b)
					m++;
				if (n / m == b)
				{
					ok = true;
					cout << n << " " << m << endl;
					break;
				}
			}
		}
		if (!ok)
			cout << "-1\n";
	}
	return 0;
}