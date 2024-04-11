#include <bits/stdc++.h>
using namespace std;
int t, n, xm, xn, x, ym, yn, y;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		xm = xn = ym = yn = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			xm = max(xm, x);
			xn = min(xn, x);
			ym = max(ym, y);
			yn = min(yn, y);
		}
		cout << (abs(xm) + abs(xn) + abs(ym) + abs(yn)) * 2 << endl;		
	}
	return 0;
}