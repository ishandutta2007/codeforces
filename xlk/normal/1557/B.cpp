#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[100020];
int t, n, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + n);
		for (int i = 1; i < n; i++)
		{
			if (a[i - 1].second + 1 != a[i].second)
			{
				k--;
			}
		}
		cout << (k > 0 ? "Yes" : "No") << endl;
	}
	return 0;
}