#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		c = abs(a - b);
		if (c == 0)
		{
			cout << "0 0\n";
		}
		else
		{
			cout << c << ' ' << min(a % c, c - a % c) << endl;
		}
	}
	return 0;
}