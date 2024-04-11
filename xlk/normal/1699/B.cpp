#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				cout << (((i ^ j) >> 1) & 1) << " ";
			}
			cout << endl;
		}
	}
	return 0;
}