#include <bits/stdc++.h>
using namespace std;
int t, n;
int p[520];
int a[520];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> p[i];
			a[p[i]] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i] != i)
			{
				reverse(p + i, p + a[i] + 1);
				break;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}
	return 0;
}