#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cout << ((n - i) % 2 ? i + 1 : max(i - 1, 1)) << " ";
		}
		cout << endl;
	}
	return 0;
}