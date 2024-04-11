#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d;
		cout << ((b > a) + (c > a) + (d > a)) << endl;
	}
	return 0;
}