#include <bits/stdc++.h>
using namespace std;
int t, a, b;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b;
		cout << (a ? a + 2 * b + 1 : 1) << endl;
	}
	return 0;
}