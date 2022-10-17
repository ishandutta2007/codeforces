#include <bits/stdc++.h>
using namespace std;
int t, n, m, x, y;
int f[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
		{
			f[i] = i;
		}
		int z = m;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			if (x == y)
			{
				z--;
			}
			else if (F(x) == F(y))
			{
				z++;
			}
			else
			{
				f[F(x)] = F(y);
			}
		}
		cout << z << endl;
	}
	return 0;
}