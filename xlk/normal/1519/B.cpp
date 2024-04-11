#include <bits/stdc++.h>
using namespace std;
int t, n, m, k;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> k;
		cout << (n * m - 1 == k ? "YES" : "NO") << endl;
	}
	return 0;
}