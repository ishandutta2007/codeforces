#include <bits/stdc++.h>
using namespace std;
int n, m, x;
int g[600020];
int a[200020];
int b[200020];
int c[200020];
int l[600020], lc;
int zi, zb, zc;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		l[lc++] = a[i];
	}
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> b[i];
		l[lc++] = b[i];
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> c[i];
		l[lc++] = c[i];
	}
	sort(l, l + lc);
	lc = unique(l, l + lc) - l;
	for (int i = 0; i < n; i++)
	{
		a[i] = lower_bound(l, l + lc, a[i]) - l;
		g[a[i]]++;
	}
	for (int i = 1; i <= m; i++)
	{
		b[i] = lower_bound(l, l + lc, b[i]) - l;
		c[i] = lower_bound(l, l + lc, c[i]) - l;
	}
	zi = zb = zc = -1;
	for (int i = 1; i <= m; i++)
	{
		if (zb < g[b[i]] || zb == g[b[i]] && zc < g[c[i]])
		{
			zb = g[b[i]];
			zc = g[c[i]];
			zi = i;
		}
	}
	cout << zi << endl;
}