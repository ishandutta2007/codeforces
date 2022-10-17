#include <bits/stdc++.h>
using namespace std;
int n, m, l;
long long a[100020];
int f[100020];
int v[100020];
int z;
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	f[x] = y;
	z--;
}
int main()
{
	cin >> n >> m >> l;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > l)
		{
			v[i] = 1;
			z++;
			if (v[i - 1])
			{
				U(i, i - 1);
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int o, p, d;
		cin >> o;
		if (o == 0)
		{
			cout << z << endl;
		}
		else if (o == 1)
		{
			cin >> p >> d;
			a[p] += d;
			if (!v[p] && a[p] > l)
			{
				v[p] = 1;
				z++;
				if (v[p - 1])
				{
					U(p, p - 1);
				}
				if (v[p + 1])
				{
					U(p, p + 1);
				}
			}
		}
	}
	return 0;
}