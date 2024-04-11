#include <bits/stdc++.h>
using namespace std;
int n, k, x, c;
long long a[200020];
set<pair<long long, int> > s;
int main()
{
	cin >> n >> k >> x;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0)
		{
			c ^= 1;
		}
		s.insert(make_pair(abs(a[i]), i));
	}
	for (int i = 0; i < k; i++)
	{
		int p = s.begin()->second;
		s.erase(s.begin());
		if (a[p] < 0)
		{
			c ^= 1;
		}
		if (c)
		{
			a[p] += x;
		}
		else
		{
			a[p] -= x;
		}
		if (a[p] < 0)
		{
			c ^= 1;
		}
		s.insert(make_pair(abs(a[p]), p));
	}
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}