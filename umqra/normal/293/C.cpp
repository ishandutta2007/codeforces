#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	ll ans = 0;
	ll n;
	cin >> n;
	if (n % 3 != 0)
	{
		puts("0");
		return 0;
	}
	n /= 3;            
	for (ll i = 2; i * i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ll k = n / i;
			ll startS = (2 - i + (int)sqrt((double)((i - 2) * (i - 2) + 4 * k))) / 2 - 5;
			for (ll s = max(startS, i); s * s <= k; s++)
			{
				if (k % s == 0)
				{
					ll p = k / s;    
					if ((((i + p - s) & (ll)1) == 0) && 
						(((i + s - p) & (ll)1) == 0) && 
						(((p + s - i) & (ll)1) == 0))
					{
						ll a = ((i + p - s) >> (ll)1);
						ll b = ((i + s - p) >> (ll)1);
						ll c = ((p + s - i) >> (ll)1);            

						if (a > 0 && b > 0 && c > 0)      
						{
							if (a != b && b != c && a != c)
								ans += 6;
							else	
							{
								if (a == b && b == c)
									ans++;
								else
									ans += 3;
							}
						}
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}