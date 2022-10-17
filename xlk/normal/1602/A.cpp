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
		pair<string, string> z = make_pair(s, "");
		for (int i = 0; i < s.size(); i++)
		{
			z = min(z, make_pair(s.substr(i, 1), s.substr(0, i) + s.substr(i + 1)));
		}
		cout << z.first << " " << z.second << endl;
	}
	return 0;
}