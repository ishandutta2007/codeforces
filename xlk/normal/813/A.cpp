#include <bits/stdc++.h>
using namespace std;
int n, x, s, m, l, r, z = 1e9;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		s += x;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r;
		if (s <= r)
		{
			z = min(z, max(s, l));
		}
	}
	if (z == 1e9)
	{
		z = -1;
	}
	cout << z << endl;
	return 0;
}