#include <bits/stdc++.h>
using namespace std;
int t, l1, r1, l2, r2;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> l1 >> r1 >> l2 >> r2;
		if (max(l1, l2) <= min(r1, r2))
		{
			cout << max(l1, l2) << endl;
		}
		else
		{
			cout << l1 + l2 << endl;
		}
	}
	return 0;
}