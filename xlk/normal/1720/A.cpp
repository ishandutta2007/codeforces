#include <bits/stdc++.h>
using namespace std;
int t;
long long a, b, c, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d;
		if (a * d == b * c)
		{
			cout << 0 << endl;
		}
		else if (a * d == 0 || b * c == 0 || (a * d) % (b * c) == 0 || (b * c) % (a * d) == 0)
		{
			cout << 1 << endl;
		}
		else
		{
			cout << 2 << endl;
		}
	}
	return 0;
}