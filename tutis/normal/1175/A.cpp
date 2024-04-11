/*input
2
59 3
1000000000000000000 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		ll a = 0;
		while (n > 0)
		{
			if (n % k == 0)
			{
				n /= k;
				a++;
			}
			else
			{
				ll x = n % k;
				a += x;
				n -= x;
			}
		}
		cout << a << "\n";
	}

	return 0;
}