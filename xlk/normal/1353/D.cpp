#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[200020];
int z[200020];
void gao(int l, int r)
{
	if (l > r)
	{
		return;
	}
	int m = (l + r) / 2;
	a[m].first = l - r;
	a[m].second = m;
	gao(l, m - 1);
	gao(m + 1, r);
}
int main()
{
	int t, n;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		gao(1, n);
		sort(a + 1, a + 1 + n);
		for (int i = 1; i <= n; i++)
		{
			z[a[i].second] = i;
		}
		for (int i = 1; i <= n; i++)
		{
			cout << z[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}