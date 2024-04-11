#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
	string s;

	getline(cin, s);

	string res;
	for (int i = 0, j = 0; i < (int)s.size(); i = j)
	{
		if (s[j] == ' ')
			j++;
		else if (s[j] == '\"')
		{
			j++;
			res.clear();
			while (s[j] != '\"')
				res.push_back(s[j]), j++;
			j++;
			cout << "<" << res << ">" << endl;
		}
		else
		{
			res.clear();
			while (j < (int)s.size() && s[j] != ' ')
				res.push_back(s[j]), j++;
			cout << "<" << res << ">" << endl;
		}
	}

	return 0;
}