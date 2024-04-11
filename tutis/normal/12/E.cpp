/*input
12
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	int a[n][n];
	for (int i = 0; i < n; i++)
		a[i][i] = 0;
	for (int t = 0; t < n; t++)
	{
		for (int c = 0; c <= t; c++)
		{
			if (c != t - c)
				a[c][t - c] = t;
		}
	}
	for (int t = 1; n - t > n / 2 + 1; t++)
	{
		int i = n - 1 - t;
		for (int j = n - i; j < n; j++)
		{
			if (i == j)
				break;
			a[i][j] = a[j][i] = j - (n - i) + 1;
		}
	}
	for (int t = 1; t < n - 1; t++)
	{
		if (t < n / 2)
			a[n - 1][t] = a[t][n - 1] = 2 * t;
		else
			a[n - 1][t] = a[t][n - 1] = 2 * (t - n / 2) + 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}