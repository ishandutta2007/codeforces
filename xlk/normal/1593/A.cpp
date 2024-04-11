#include <bits/stdc++.h>
using namespace std;
int t, a, b, c;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> a >> b >> c;
		cout << max(max(b, c) + 1 - a, 0) << ' ';
		cout << max(max(c, a) + 1 - b, 0) << ' ';
		cout << max(max(a, b) + 1 - c, 0) << endl;	
	}
	return 0;
}