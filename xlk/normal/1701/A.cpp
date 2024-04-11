#include <bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c >> d;
		cout << (a + b + c + d + 2) / 3 << endl;
	}
	return 0;
}