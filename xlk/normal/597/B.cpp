#include <bits/stdc++.h>
using namespace std;
int n, l, z;
pair<int, int> a[500020];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (l < a[i].second)
		{
			z++;
			l = a[i].first;
		}
	}
	cout << z << endl;
	return 0;
}