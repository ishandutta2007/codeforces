#include <bits/stdc++.h>
using namespace std;
int t, n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (n + 1) / 3 << " " << (n + 5) / 3 << " " << (n - 3) / 3 << endl;
	}
	return 0;
}