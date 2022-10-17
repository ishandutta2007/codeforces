#include <bits/stdc++.h>
using namespace std;
int t;
string s;
char c;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s >> c;
		int f = 1;
		for (int i = 0; i < s.size(); i += 2)
		{
			if (s[i] == c)
			{
				cout << "YES" << endl;
				f = 0;
				break;
			}
		}
		if (f)
		{
			cout << "NO" << endl;	
		}
	}
	return 0;
}