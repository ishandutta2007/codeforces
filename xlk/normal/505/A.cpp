#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
	cin >> s;
	for (int i = 0; i <= s.size(); i++)
	{
		for (char j = 'a'; j <= 'z'; j++)
		{
			string t = s.substr(0, i) + j + s.substr(i);
			string r = t;
			reverse(r.begin(), r.end());
			if (r == t)
			{
				cout << t << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
	return 0;
}