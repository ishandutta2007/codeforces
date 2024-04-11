#include <bits/stdc++.h>
using namespace std;
int t, n, a[100];
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < n; i++)
		{
			if (a[i] != a[(i + 1) % n] && a[i] != a[(i + 2) % n])
			{
				cout << i + 1 << endl;
			}
		}
	}
	return 0;
}