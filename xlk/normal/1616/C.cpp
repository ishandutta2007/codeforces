#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[80];
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
		int z = n - 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int c = 0;
				for (int k = 0; k < n; k++)
				{
					if (a[k] * (j - i) != (a[i] * (j - k) + a[j] * (k - i)))
					{
						c++;
					}
				}
				z = min(z, c);
			}
		}
		cout << z << endl;
	}
}