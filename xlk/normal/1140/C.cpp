#include <bits/stdc++.h>
using namespace std;
int n, m;
pair<int, int> a[300020];
long long c, z;
multiset<int> s;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--)
	{
		s.insert(a[i].second);
		c += a[i].second;
		if (s.size() > m)
		{
			c -= *s.begin();
			s.erase(s.begin());
		}
		z = max(z, c * a[i].first);
	}
	cout << z << endl;
	return 0;
}