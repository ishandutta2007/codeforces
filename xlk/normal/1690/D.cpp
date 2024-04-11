#include <bits/stdc++.h>
using namespace std;
int t, n, m;
char c[200020];
int s[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++)
		{
			s[i + 1] = s[i] + (c[i] == 'W');
		}
		int z = m;
		for (int i = m; i <= n; i++)
		{
			z = min(z, s[i] - s[i - m]);
		}
		cout << z << endl;
	}
	return 0;
}