#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int c[200020];
int G(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
void R(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			c[i] = 0;
		}
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x < i)
			{
				z += G(x - 1);
				R(i, 1);
			}
		}
		cout << z << endl;
	}
	return 0;
}