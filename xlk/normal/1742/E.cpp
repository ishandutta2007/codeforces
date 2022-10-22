#include <bits/stdc++.h>
using namespace std;
int t, n, q, x;
long long a[200020];
long long s[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> q;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			s[i + 1] = s[i] + a[i];
			if (i > 0)
			{
				a[i] = max(a[i], a[i - 1]);
			}
		}
		for (int i = 0; i < q; i++)
		{
			cin >> x;
			cout << s[upper_bound(a, a + n, x) - a] << " ";
		}
		cout << endl;
	}
	return 0;
}