#include <bits/stdc++.h>
using namespace std;
int t, n;
bool F(int n)
{
	for (int i = 0; i <= n; i += 2020)
	{
		if ((n - i) % 2021 == 0)
		{
			return true;
		}
	}
	return false;
}
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		cout << (F(n) ? "YES" : "NO") << endl;
	}
	return 0;
}