#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c = 0;
		for (int i = 1; i <= n; i = i * 10 + 1)
		{
			for (int j = 1; j <= 9; j++)
			{
				if (i * j <= n)
				{
					c++;
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}