#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> m;
		if (a < b)
		{
			swap(a, b);
		}
		if (a < c)
		{
			swap(a, c);
		}
		cout << (a - 1 - b - c <= m && m <= a + b + c - 3 ? "YES" : "NO") << endl;
	}
	return 0;
}