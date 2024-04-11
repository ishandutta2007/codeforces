#include <bits/stdc++.h>
using namespace std;
int s, n;
pair<int, int> a[1020];
int main()
{
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (s > a[i].first)
		{
			s += a[i].second;
		}
		else
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}