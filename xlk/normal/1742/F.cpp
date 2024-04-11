#include <bits/stdc++.h>
using namespace std;
int t, q, d, k;
string x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long a[2][2] = {{0, 1}, {0, 1}};
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> d >> k >> x;
			d--;
			for (char c : x)
			{
				a[d][c == 'a'] += k;
			}
			if (a[1][0] || a[0][1] < a[1][1] && a[0][0] == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}