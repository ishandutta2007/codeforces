#include <bits/stdc++.h>
using namespace std;
int t, n;
char c;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> c >> s;
		int z = 0, p = 0, n = s.size();
		for (int i = 0; i < n; i++)
		{
			if (s[i] == c)
			{
				z++;
				p = i + 1;
			}
		}
		if (z == n)
		{
			cout << 0 << endl;
		}
		else if (2 * p > n)
		{
			cout << 1 << endl << p << endl;
		}
		else
		{
			cout << 2 << endl << n << ' ' << n - 1 << endl;
		}

	}
	return 0;
}