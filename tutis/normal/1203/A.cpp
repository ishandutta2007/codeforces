/*input
5
4
1 2 3 4
3
1 3 2
5
1 2 3 5 4
1
1
5
3 2 1 5 4
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
		int n;
		cin >> n;
		int p[n];
		for (int &i : p)
			cin >> i;
		bool ok = false;
		{
			bool k = true;
			int j = find(p, p + n, 1) - p;
			for (int d = 0; d + 1 < n; d++)
			{
				k &= (p[(j + d) % n] - p[(j + d + 1) % n]) == -1;
			}
			ok |= k;
		}
		{
			bool k = true;
			int j = find(p, p + n, 1) - p;
			for (int d = 0; d + 1 < n; d++)
			{
				k &= (p[(j + n - d) % n] - p[(j + n - d - 1) % n]) == -1;
			}
			ok |= k;
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}