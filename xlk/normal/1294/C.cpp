#include <bits/stdc++.h>
using namespace std;
void gao(int n)
{
	for (int i = 2; i * i < n; i++)
	{
		if (n % i == 0)
		{
			for (int j = i + 1; j * j < n / i; j++)
			{
				if (n / i % j == 0)
				{
					cout << "YES" << endl;
					cout << i << ' ' << j << ' ' << n / i / j << endl;
					return;
				}
			}
		}
	}
	cout << "NO" << endl;
	return;
}
int main()
{
	int t, n;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		gao(n);
	}
	return 0;
}