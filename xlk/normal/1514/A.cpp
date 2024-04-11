#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int f = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			int r = sqrt(x);
			if (r * r != x)
			{
				f = 1;
			}
		}
		puts(f ? "YES" : "NO");
	}
	return 0;
}