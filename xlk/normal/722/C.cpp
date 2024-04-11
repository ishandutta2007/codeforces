#include <bits/stdc++.h>
using namespace std;
int n;
int p[100020];
int v[100020];
int f[100020];
long long c[100020];
long long z[100020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
	c[y] += c[x];
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		f[i] = i;
	}
	for (int i = n; i > 0; i--)
	{
		v[p[i]] = 1;
		if (v[p[i] - 1])
		{
			U(p[i], p[i] - 1);
		}
		if (v[p[i] + 1])
		{
			U(p[i], p[i] + 1);
		}
		z[i - 1] = max(z[i], c[F(p[i])]);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << z[i] << endl;
	}
	return 0;
}