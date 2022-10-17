#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[2020];
bool cmp(int x, int y)
{
	return x % 2 < y % 2;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, cmp);
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (__gcd(a[i], a[j] * 2) > 1)
				{
					z++;
				}
			}
		}
		cout << z << endl;
	}
	return 0;
}