#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		map<int, int> c;
		vector<pair<int, int> > b;
		for (int i = 0; i < n; i++)
		{
			if (c[a[i]]++ < m)
			{
				b.push_back(make_pair(a[i], i));
			}
		}
		sort(b.begin(), b.end());
		vector<int> z;
		z.resize(n);
		for (int i = 0; i < b.size() / m * m; i++)
		{
			z[b[i].second] = i % m + 1;
		}
		for (int i = 0; i < n; i++)
		{
			cout << z[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}