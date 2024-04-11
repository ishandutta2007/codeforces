#include <bits/stdc++.h>
using namespace std;
int t, n, l, r, c;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int mnl = 2e9, lc = 0;
		int mxr = -1, rc = 0;
		int mxlen = 0, lenc = 1e9;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> l >> r >> c;
			if (mnl > l || mnl == l && lc > c)
			{
				mnl = l;
				lc = c;
			}
			if (mxr < r || mxr == r && rc > c)
			{
				mxr = r;
				rc = c;
			}
			if (mxlen < r - l || mxlen == r - l && lenc > c)
			{
				mxlen = r - l;
				lenc = c;
			}
			if (mxr - mnl == mxlen)
			{
				cout << min(lenc, lc + rc) << endl;
			}
			else
			{
				cout << lc + rc << endl;
			}
		}
	}
	return 0;
}