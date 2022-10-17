#include <bits/stdc++.h>
using namespace std;
int t, n, m;
pair<pair<int, int>, int> a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a[i].first.second >> a[i].first.first;
			a[i].second = i + 1;
		}
		sort(a, a + m);
		long long z = 0;
		for (int i = 0; i < 2 * n; i++)
		{
			z += a[i].first.first;
			swap(a[i].first.first, a[i].first.second);
		}
		sort(a, a + 2 * n);
		cout << z << endl;
		for (int i = 0; i < n; i++)
		{
			cout << a[i].second << " " << a[2 * n - 1 - i].second << endl;
		}
	}
	return 0;
}