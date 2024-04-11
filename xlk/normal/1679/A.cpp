#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		if (n < 4 || n & 1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << (n + 4) / 6 << " " << n / 4 << endl;
		}
	}
	return 0;
}