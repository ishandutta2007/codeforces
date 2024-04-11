/*input
7 4
1 1 3
1 2 5
0 5 6
1 6 7

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int t[m], l[m], r[m];
	int a[n + 1];
	fill_n(a, n + 1, -1);
	a[0] = 1e5;
	for (int i = 0; i < m; i++)
	{
		cin >> t[i] >> l[i] >> r[i];
		if (t[i] == 1)
		{
			for (int j = l[i] + 1; j <= r[i]; j++)
			{
				a[j] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (t[i] == 0)
		{
			bool ok = false;
			for (int j = l[i] + 1; j <= r[i]; j++)
			{
				ok |= (a[j] == -1);
			}
			if (ok == false)
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
	{
		a[i] += a[i - 1];
		cout << a[i] << " ";
	}
	cout << "\n";

}