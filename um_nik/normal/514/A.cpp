#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

string s;
int n;

int main()
{
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
		s[i] = min(s[i], (char)('0' + (9 - (s[i] - '0'))));
	if (s[0] == '0')
		s[0] = '9';
	cout << s << endl;

	return 0;
}