#include <bits/stdc++.h>
using namespace std;
int t, n;
string a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> a >> b;
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i] == '1' && b[i] == '1')
			{
				f = 0;
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}