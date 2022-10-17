#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c;
		cout << (a + c) % 2 << endl;
	}
	return 0;
}