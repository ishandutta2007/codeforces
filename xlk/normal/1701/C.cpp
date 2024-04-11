#include <bits/stdc++.h>
using namespace std;
int t, n, m, x;
int c[200020];
bool ok(int M)
{
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		if (c[i] > M)
		{
			s += c[i] - M;
		}
		else
		{
			s -= (M - c[i]) / 2;
		}
	}
	return s <= 0;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			c[i] = 0;
		}
		for (int i = 0; i < m; i++)
		{
			cin >> x;
			c[x]++;
		}
		int L = 0, R = (m / n + 1) * 2;
		while (L < R - 1)
		{
			int M = (L + R) / 2;
			if (ok(M))
			{
				R = M;
			}
			else
			{
				L = M;
			}
		}
		cout << R << endl;
	}
	return 0;
}