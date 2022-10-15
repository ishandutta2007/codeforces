/**
1 5
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ull;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ull m, b;
	cin >> m >> b;
	ull ans = 0;
	for (ull x = 0; x <= 10000000; x++)
	{
		if (x % m == 0)
		{
			ull y = ((-x) / m) + b;
			if (y >= 0)
			{
				ans = max(ans, (y + 1) * (x) * (x + 1) / 2 + (x + 1) * (y) * (y + 1) / 2);
			}
		}
	}
	cout << ans;
}