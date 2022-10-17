#include <bits/stdc++.h>
using namespace std;
pair<int, pair<int, int> > a[200020];
int n, m, q;
int w[200020];
int f[200020];
int c[200020];
long long z[200020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i < n; i++)
	{
		cin >> a[i].second.first >> a[i].second.second >> a[i].first;
	}
	sort(a + 1, a + n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 1; i < n; i++)
	{
		int x = F(a[i].second.first);
		int y = F(a[i].second.second);
		z[i] = z[i - 1] + (long long)c[x] * c[y];
		w[i] = a[i].first;
		f[x] = y;
		c[y] += c[x];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> q;
		cout << z[upper_bound(w, w + n, q) - w - 1] << " ";
	}
	return 0;
}