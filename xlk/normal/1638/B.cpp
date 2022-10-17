#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int l[2] = {};
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (x < l[x & 1])
			{
				f = 0;
			}
			l[x & 1] = x;
		}
		cout << (f ? "Yes" : "No") << endl;
	}
	return 0;
}