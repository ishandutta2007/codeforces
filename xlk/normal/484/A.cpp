#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	long long l, r;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> l >> r;
		while ((l | l + 1) <= r)
		{
			l |= l + 1;
		}
		cout << l << endl;
	}
	return 0;
}