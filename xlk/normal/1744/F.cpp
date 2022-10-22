#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[200020];
int p[200020];
long long C(long long x)
{
	return x < 0 ? 0 : x * (x - 1) / 2;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			p[a[i]] = i;
		}
		int l = p[0];
		int r = p[0];
		long long z = 0;
		for (int i = 1; i <= n; i++) // subsegment contains 0 .. i - 1 does not contain i
		{
			l = min(l, p[i - 1]);
			r = max(r, p[i - 1]);
			int f = l; // max number of elements extend to the left
			int g = n - 1 - r; // max number of elements extend to the right
			int h = i - (r - l + 1 - i); // max number of elements extend to both sides
			if (i < n)
			{
				if (p[i] < l)
				{
					f = l - p[i] - 1;
				}
				else if (p[i] > r)
				{
					g = p[i] - r - 1;
				}
				else
				{
					continue;
				}
			}
			z += C(h + 2);
			z -= C(h - f + 1);
			z -= C(h - g + 1);
			z += C(h - f - g);
		}
		cout << z << endl;
	}
	return 0;
}