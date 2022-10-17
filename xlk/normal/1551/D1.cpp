#include <bits/stdc++.h>
using namespace std;
int t, n, m, l;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> l;
		if (n % 2 == 0 && m % 2 == 0)
		{
			cout << (l % 2 == 0 ? "YES" : "NO") << endl;
		}
		else if (n % 2 == 0)
		{
			cout << (l % 2 == 0 && l <= n * (m / 2) ? "YES" : "NO") << endl;
		}
		else if (m % 2 == 0)
		{
			cout << (l >= m / 2 && (l - m / 2) % 2 == 0 ? "YES" : "NO") << endl;
		}
		else
		{
			assert(false);
		}
	}
	return 0;
}