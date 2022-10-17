#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int c = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> x;
			c += x & 1;
		}
		cout << (c == 2 * n - c ? "Yes" : "No") << endl;
	}
	return 0;
}