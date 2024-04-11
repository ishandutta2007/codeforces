#include <iostream>
#include <string>
#include <clocale>
using namespace std;

int main()
{
	string s;
	int t;

	cin >> s;
	cin >> t;

	for (int i = 0; i < (int)s.length(); i++)
	{
		int c = islower(s[i]) ? s[i] - 'a' : s[i] - 'A';
		if (c < t)
			s[i] = c + 'A';
		else
			s[i] = c + 'a';
	}
	cout << s << endl;

	return 0;
}