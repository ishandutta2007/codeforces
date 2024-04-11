#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int x;
string s;

int main()
{
	cin >> x >> s;
	if (s[3] >= '6')
		s[3] = '0';
	if (x == 12)
	{
		if (s[0] > '1')
		{
			if (s[1] == '0')
				s[0] = '1';
			else
				s[0] = '0';
		}
		else if (s[0] == '1')
		{
			if (s[1] > '2')
				s[1] = '0';
		}
		else
		{
			if (s[1] == '0')
				s[1] = '1';
		}
	}
	else
	{
		if (s[0] > '2' || (s[0] == '2' && s[1] >= '4'))
			s[0] = '0';
	}
	cout << s << endl;

	return 0;
}