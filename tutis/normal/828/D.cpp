/***
6 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll d = (n - 2) / k;
	while (d <= n)
	{
		for (ll a = n; a >= 0; a--)
		{
			if ((n - 1 - a * (d)) >= 0)
			{
				if ((n - 1 - a * (d)) % (d + 1) == 0)
				{
					ll b = (n - 1 - a * (d)) / (d + 1);
					if (a + b == k && a * d + b * (d + 1) == n - 1)
					{
						if (b == 0)
							cout << d * 2 << "\n";
						else if (b == 1)
							cout << d * 2 + 1 << "\n";
						else
							cout << d * 2 + 2 << "\n";
						ll jau = 2;
						for (ll k = 0; k < a; k++)
						{
							cout << jau << " 1\n";
							for (ll c = 0; c < d - 1; c++)
							{
								cout << jau + c << " " << jau + c + 1 << "\n";
							}
							jau += d;
						}
						for (ll k = 0; k < b; k++)
						{
							cout << jau << " 1\n";
							for (ll c = 0; c < d; c++)
							{
								cout << jau + c << " " << jau + c + 1 << "\n";
							}
							jau += d + 1;
						}
						return 0;
					}
				}
			}
		}
		d++;
	}
}