#include <bits/stdc++.h>
using namespace std;
int t;
char s[200020];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int n = strlen(s);
		int v[26] = {};
		int z = 0;
		for (int i = 0; i < n; i++)
		{
			if (v[s[i] - 'a'])
			{
				z += 2;
				memset(v, 0, sizeof v);
			}
			else
			{
				v[s[i] - 'a'] = 1;
			}
		}
		cout << n - z << endl;
	}
	return 0;
}