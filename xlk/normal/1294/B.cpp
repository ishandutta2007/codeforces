#include <bits/stdc++.h>
using namespace std;
int t, n;
pair<int, int> a[1020];
void zuo()
{
	sort(a, a + n + 1);
	for (int i = 1; i <= n; i++)
	{
		if (a[i].second < a[i - 1].second)
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = a[i - 1].first; j < a[i].first; j++)
		{
			cout << "R";
		}
		for (int j = a[i - 1].second; j < a[i].second; j++)
		{
			cout << "U";
		}
	}
	cout << endl;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i].first >> a[i].second;
		}
		zuo();
	}
	return 0;
}