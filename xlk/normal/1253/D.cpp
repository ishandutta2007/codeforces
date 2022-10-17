#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int f[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x > y)
	{
		swap(x, y);
	}
	f[x] = y;	
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		U(x, y);
	}
	for (int i = 1; i < n; i++)
	{
		if (F(i) != F(i + 1))
		{
			if (F(i) > i + 1)
			{
				z++;
				U(i, i + 1);
			}
		}
	}
	cout << z << endl;
	return 0;
}