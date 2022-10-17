#include <bits/stdc++.h>
using namespace std;
int t, n, q, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long f = 0, g = 0;
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			tie(f, g) = make_pair(max(f, g + x), max(g, f - x));
		}
		cout << f << endl;
	}
	return 0;
}