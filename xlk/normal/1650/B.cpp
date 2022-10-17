#include <bits/stdc++.h>
using namespace std;
int t, l, r, a;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> l >> r >> a;
		int z = r / a + r % a;
		if (l <= r / a * a - 1)
		{
			z = max(z, r / a - 1 + a - 1);
		}
		cout << z << endl;
	}
	return 0;
}