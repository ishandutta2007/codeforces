/*input
3
1 1
1 4
2 5
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
		ll b, w;
		cin >> b >> w;
		if (b > 3 * w + 1 || w > 3 * b + 1)
		{
			cout << "NO\n";
			continue;
		}
		cout << "YES\n";
		int y0 = 2;
		if (b >= w)
			y0 = 3;
		int y1 = y0;
		for (int y = y0;; y++)
		{
			if (y % 2 == 0)
			{
				if (w == 0)
					break;
				w--;
			}
			else
			{
				if (b == 0)
					break;
				b--;
			}
			cout << "2 " << y << "\n";
			y1 = y;
		}
		for (int c : {1, 3})
			for (int y = y0; y <= y1; y++)
			{
				if (y % 2 == 1)
				{
					if (w == 0)
						continue;
					w--;
				}
				else
				{
					if (b == 0)
						continue;
					b--;
				}
				cout << c << " " << y << "\n";
			}
	}
}