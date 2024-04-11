#include <bits/stdc++.h>
using namespace std;
int n, l, x, c, z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > l)
		{
			z = max(z, ++c);
		}
		else
		{
			c = 1;
		}
		l = x;
	}
	cout << z << endl;
	return 0;
}