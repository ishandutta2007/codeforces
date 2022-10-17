#include <bits/stdc++.h>
using namespace std;
int n, c, v;
int a[200020];
int b[200020];
int f[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		int x = F(i);
		int y = F(a[i]);
		if (x != y)
		{
			f[x] = y;
		}
		else
		{
			b[c++] = i;
			if (i == a[i])
			{
				v = i;
			}
		}
	}
	if (v)
	{
		cout << c - 1 << endl;
	}
	else
	{
		cout << c << endl;
		v = b[0];
	}
	for (int i = 0; i < c; i++)
	{
		a[b[i]] = v;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}