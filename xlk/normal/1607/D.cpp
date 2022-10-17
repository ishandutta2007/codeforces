#include <bits/stdc++.h>
using namespace std;
int t, n;
pair<char, int> a[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].second;
		}
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
		}
		sort(a, a + n);
		int f = 1;
		for (int i = 0; i < n; i++)
		{
			if (a[i].first == 'B')
			{
				if (a[i].second < i + 1)
				{
					f = 0;
					break;
				}
			}
			else
			{
				if (a[i].second > i + 1)
				{
					f = 0;
					break;
				}
			}
		}
		cout << (f ? "YES" : "NO") << endl;
	}
	return 0;
}