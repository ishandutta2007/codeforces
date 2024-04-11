#include <bits/stdc++.h>
using namespace std;
int t, n, a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n, greater<int>());
		long long s = 0;
		for (int i = 0; i < n; i++)
		{
			if (i & 1) // Bob
			{
				if (a[i] & 1) // odd
				{
					s -= a[i];
				}
			}
			else // Alice
			{
				if (~a[i] & 1) // even
				{
					s += a[i];
				}
			}
		}
		if (s > 0)
		{
			cout << "Alice" << endl;
		}
		else if (s < 0)
		{
			cout << "Bob" << endl;
		}
		else
		{
			cout << "Tie" << endl;
		}
	}
	return 0;
}