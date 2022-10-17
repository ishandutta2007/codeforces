#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long n, z = 0;
		cin >> n;
		if (n % 2050)
		{
			z = -1;
		}
		else
		{
			for (n /= 2050; n > 0; n /= 10)
			{
				z += n % 10;
			}
		}
		cout << z << endl;
	}
	return 0;
}