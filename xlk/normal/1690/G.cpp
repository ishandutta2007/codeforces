#include <bits/stdc++.h>
using namespace std;
int t, n, q, x, y;
int a[100020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> q;
		int mn = 2e9;
		set<int> s;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			if (mn > a[i])
			{
				mn = a[i];
				s.insert(i);
			}
		}
		for (int i = 0; i < q; i++)
		{
			cin >> x >> y;
			a[x] -= y;
			if (a[x] < a[*--s.upper_bound(x)])
			{
				s.insert(x);
			}
			auto it = s.upper_bound(x);
			while (it != s.end() && a[x] <= a[*it])
			{
				s.erase(it++);
			}
			cout << s.size() << " ";
		}
		cout << endl;
	}
	return 0;
}