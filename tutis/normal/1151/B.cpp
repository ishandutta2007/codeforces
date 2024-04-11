/*input
3 2
0 0
0 0
0 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int a[n + 1][m + 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	int x = 0;
	for (int i = 1; i <= n; i++)
		x ^= a[i][1];
	if (x != 0)
	{
		cout << "TAK\n";
		for (int i = 1; i <= n; i++)
			cout << 1 << " ";
		cout << "\n";
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != a[i][1])
			{
				cout << "TAK\n";
				for (int c = 1; c <= n; c++)
				{
					if (c == i)
						cout << j << " ";
					else
						cout << "1 ";
				}
				return 0;
			}
		}
	cout << "NIE\n";
}