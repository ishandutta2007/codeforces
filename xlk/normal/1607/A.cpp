#include <bits/stdc++.h>
using namespace std;
int t;
int p[128];
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		p[s[i]] = i;
	}
		cin >> s;
		int z = 0;
		for (int i = 1; i < s.size(); i++)
		{
			z += abs(p[s[i]] - p[s[i - 1]]);
		}
		cout << z << endl;
	}
	return 0;
}