#include <bits/stdc++.h>
using namespace std;
int t, n, s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		cout << s / (n / 2 + 1) << endl;
	}
	return 0;
}