#include <bits/stdc++.h>
using namespace std;
int t, n;
bool good(int x)
{
	while (x > 0)
	{
		if (x % 3 == 2)
		{
			return false;
		}
		x /= 3;
	}
	return true;
}
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		while (!good(n))
		{
			n++;
		}
		cout << n << endl;
	}
}