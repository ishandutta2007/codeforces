#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100020];
bool ok(long long M)
{
	int c = 0;
	long long t = 0;
	for (int i = 1; i <= n; i++)
	{
		t--;
		if (t < 0)
		{
			t = 0;
		}
		int u = a[i];
		while (u > t)
		{
			u -= t;
			c++;
			if (c > m)
			{
				return false;
			}
			t = M - i;
			if (t < 0)
			{
				return false;
			}
		}
		t -= u;
	}
	return true;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	long long L = 0, R = 1e15;
	while (L < R - 1)
	{
		long long M = (L + R) / 2;
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
	return 0;
}