#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
string p, q, s, t;
long long u, v, x, y;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		t = s;
		reverse(t.begin(), t.end());
		x = y = 1e18;
		if (s >= p)
		{
			x = min(x, u);
		}
		if (s >= q)
		{
			x = min(x, v);
		}
		if (t >= p)
		{
			y = min(y, u + a[i]);
		}
		if (t >= q)
		{
			y = min(y, v + a[i]);
		}
		p = s;
		q = t;
		u = x;
		v = y;
	}
	u = min(u, v);
	if (u == 1e18)
	{
		u = -1;
	}
	cout << u << endl;
	return 0;
}