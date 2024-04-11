#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		int s = 1, z = b - a;
		while (a < b)
		{
			int e = a & ~b, d = b;
			if (e)
			{
				int f = 32 - __builtin_clz(e);
				d &= -1 << f;
			}
			z = min(z, (a | d) - b + s);
			s += a & -a;
			a += a & -a;
		}
		cout << z << endl;
	}
	return 0;
}