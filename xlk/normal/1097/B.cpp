#include <bits/stdc++.h>
using namespace std;
int n;
int a[15];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 1 << n; i++)
	{
		int s = 0;
		for (int j = 0; j < n; j++)
		{
			if (i >> j & 1)
			{
				s += a[j];
			}
			else
			{
				s -= a[j];
			}
		}
		if (s % 360 == 0)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}