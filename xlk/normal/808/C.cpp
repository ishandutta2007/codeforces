#include <bits/stdc++.h>
using namespace std;
struct N
{
	int c, t, i;
} a[120];
bool cmpc(const N&a, const N&b)
{
	return a.c > b.c;
}
bool cmpi(const N&a, const N&b)
{
	return a.i < b.i;
}
int n, w;
int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].c;
		a[i].t = (a[i].c + 1) / 2;
		w -= a[i].t;
		a[i].i = i;
	}
	if (w < 0)
	{
		cout << -1 << endl;
	}
	else
	{
		sort(a, a + n, cmpc);
		for (int i = 0; i < n; i++)
		{
			int t = min(w, a[i].c - a[i].t);
			a[i].t += t;
			w -= t;
		}
		sort(a, a + n, cmpi);
		for (int i = 0; i < n; i++)
		{
			cout << a[i].t << " ";
		}
	}
	return 0;
}