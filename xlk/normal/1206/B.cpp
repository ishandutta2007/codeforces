#include <bits/stdc++.h>
using namespace std;
int n, x, c, d;
long long z;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 0)
		{
			z += x - 1;
		}
		else if (x < 0)
		{
			z += -1 - x;
			c++;
		}
		else
		{
			z++;
			d++;
		}
	}
	if (d == 0 && c % 2 == 1)
	{
		z += 2;
	}
	cout << z << endl;
	return 0;
}