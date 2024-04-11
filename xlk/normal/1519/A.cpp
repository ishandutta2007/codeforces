#include <bits/stdc++.h>
using namespace std;
int t;
long long r, b, d;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> r >> b >> d;
		cout << (min(r, b) * (d + 1) < max(r, b) ? "NO" : "YES") << endl;
	}
	return 0;
}