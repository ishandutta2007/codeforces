/*input
ftphttprururu
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	string s;
	cin >> s;
	if (s[0] == 'f')
	{
		s.erase(s.begin());
		s.erase(s.begin());
		s.erase(s.begin());
		cout << "ftp://";
	}
	else
	{
		s.erase(s.begin());
		s.erase(s.begin());
		s.erase(s.begin());
		s.erase(s.begin());
		cout << "http://";
	}
	for (int i = 2; i < (int)s.size(); i++)
	{
		if (s[i - 1] == 'r' && s[i] == 'u')
		{
			cout << s.substr(0, i - 1) << ".ru";
			s = s.substr(i + 1, s.size() - i - 1);
			break;
		}
	}
	if (s.size() > 0)
		cout << "/" << s;
	cout << "\n";
}