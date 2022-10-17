#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> s;
		if (n >= 2 && s[0] == s[1])
		{
			cout << s[0] << s[1] << endl;
			continue;
		}
		string z;
		z += s[0];
		for (int i = 1; i < n; i++)
		{
			if (s[i] > s[i - 1])
			{
				break;
			}
			z += s[i];
		}
		for (int i = z.size(); i--;)
		{
			z += z[i];
		}
		cout << z << endl;
	}
	return 0;
}