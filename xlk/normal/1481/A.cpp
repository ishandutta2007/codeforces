#include <bits/stdc++.h>
using namespace std;
int t, x, y;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int L = 0, R = 0, U = 0, D = 0;
		cin >> x >> y >> s;
		for (char c: s)
		{
			if (c == 'L')
			{
				L--;
			}
			else if (c == 'R')
			{
				R++;
			}
			else if (c == 'D')
			{
				D--;
			}
			else
			{
				U++;
			}
		}
		cout << (L <= x && x <= R && D <= y && y <= U ? "YES" : "NO") << endl;
	}
	return 0;
}