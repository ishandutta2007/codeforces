#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		long long n;
		cin >> n;
		n = n / 2;
		cout << n * (n + 1) * (2 * n + 1) / 3 * 4 << endl;
	}
	return 0;
}