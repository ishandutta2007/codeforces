#include <bits/stdc++.h>
using namespace std;
int n, q, c, o, x, y, l;
int a[200020];
int b[200020];
long long s;
int main()
{
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		s += a[i];
	}
	for (int i = 0; i < q; i++)
	{
		cin >> o;
		if (o == 1)
		{
			cin >> x >> y;
			if (b[x] < c)
			{
				a[x] = l;
				b[x] = c; 
			}
			s -= a[x];
			a[x] = y;
			s += a[x];
		}
		else
		{
			cin >> y;
			s = (long long)n * y;
			c++;
			l = y;
		}
		cout << s << endl;
	}
	return 0;
}