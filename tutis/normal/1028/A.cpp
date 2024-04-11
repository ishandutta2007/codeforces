/*input
5 6
WWBBBW
WWBBBW
WWBBBW
WWWWWW
WWWWWW
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int x = 0, y = 0, k = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char g;
			cin >> g;
			if (g == 'B')
			{
				x += i;
				y += j;
				k++;
			}
		}
	}
	cout << (x / k) << " " << (y / k) << "\n";


}