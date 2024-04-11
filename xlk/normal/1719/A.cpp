#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m;
		cout << ((n + m & 1) ? "Burenka" : "Tonya") << endl;
	}
	return 0;
}