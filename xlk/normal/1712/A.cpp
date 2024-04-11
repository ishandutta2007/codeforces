#include <bits/stdc++.h>
using namespace std;
int t, n, k, x;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			if (i < k && x > k)
			{
				z++;
			}
		}
		cout << z << endl;
	}
	return 0;
}