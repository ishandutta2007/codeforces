#include <bits/stdc++.h>
using namespace std;
int t, n;
int s[200020];
int f[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> s[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cin >> f[i];
			cout << f[i] - max(s[i], f[i - 1]) << " ";
		}
		cout << endl;
	}
	return 0;
}