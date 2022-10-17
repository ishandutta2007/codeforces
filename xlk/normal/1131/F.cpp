#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int f[150020];
int b[150020];
int c[150020];
int z[150020];
int F(int x)
{
	if (f[x] == x)
	{
		return x;
	}
	int fx = F(f[x]);
	b[x] += b[f[x]];
	f[x] = fx;
	return f[x];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
		b[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		f[y] = x;
		b[y] = c[x];
		c[x] += c[y];
	}
	for (int i = 1; i <= n; i++)
	{
		F(i);
		z[b[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cout << z[i] << " ";
	}
	return 0;
}