#include <bits/stdc++.h>
using namespace std;
int t, n, k1, k2, w, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k1 >> k2 >> w >> b;
		cout << ((k1 + k2) / 2 >= w && (2 * n - k1 - k2) / 2 >= b ? "Yes" : "No") << endl;
	}
	return 0;
}