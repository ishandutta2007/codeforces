#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << 2 << endl;
		for (int i = 1; i <= n; i += 2)
		{
			for (int j = i; j <= n; j *= 2)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
	return 0;
}