/***
5
weird
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<char>X = {'a', 'e', 'i', 'o', 'y', 'u'};
bool removeV(string &s)
{
	string ret = "";
	for (int i = 1; i < s.size(); i++)
	{
		if (X.count(s[i]) && X.count(s[i - 1]))
		{
			for (int j = 0; j < s.size(); j++)
				if (j != i)
					ret.push_back(s[j]);
			s = ret;
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	while (removeV(s));
	cout << s;
}