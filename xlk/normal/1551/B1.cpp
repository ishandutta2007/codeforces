#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int c[26] = {};
		for (int i = 0; i < s.size(); i++)
		{
			c[s[i] - 'a']++;
		}
		int z = 0;
		for (int i = 0; i < 26; i++)
		{
			z += min(2, c[i]);
		}
		cout << z / 2 << endl;
	}
	return 0;
}