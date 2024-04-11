#include <bits/stdc++.h>
using namespace std;
int n, c;
int x[120];
int y[120];
int f[120];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		c--;
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i];
		f[i] = i;
	}
	c = n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (x[i] == x[j] || y[i] == y[j])
			{
				U(i, j);
			}
		}
	}
	cout << c - 1 << endl;
	return 0;
}