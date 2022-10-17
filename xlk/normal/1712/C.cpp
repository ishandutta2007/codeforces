#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		map<int, int> u, v;
		int c = 0, d = 0, z = 0, p = n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (v[a[i]] == 0)
			{
				v[a[i]] = i;
				c++;
			}
		}
		for (int i = n; i > 0; i--)
		{
			if (i < n && a[i] > a[i + 1])
			{
				break;
			}
			if (u[a[i]] == 0)
			{
				u[a[i]] = 1;
				p = min(p, v[a[i]]);
				d++;
			}
			if (p == i)
			{
				z = d;
			}
		}
		cout << c - z << endl;
	}
	return 0;
}