#include <bits/stdc++.h>
using namespace std;
int t, n;
pair<int, int> a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].first;
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].second;
		}
		sort(a, a + n + 1);
		long long z = a[n].first, s = 0;
		for (int i = n; i > 0; i--)
		{
			s += a[i].second;
			z = min(z, max((long long)a[i - 1].first, s));
		}
		cout << z << endl;
	}
	return 0;
}