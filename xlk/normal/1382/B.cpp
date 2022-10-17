#include <bits/stdc++.h>
using namespace std;
int t, n, a[100020];
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
		a[n - 1]++;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > 1)
			{
				cout << (i & 1 ? "Second" : "First") << endl;
				break;
			}
		}
	}
	return 0;
}