#include <bits/stdc++.h>
using namespace std;
int t, n, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		int z = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			z = max(z, x - i);
		}
		cout << z << endl;
	}
	return 0;
}