#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	string s;
	cin >> s;

	int i = 0;
	while (i = s.find("WUB", i), i != string::npos)
		s.replace(i, 3, string(" "));

	string res;
	for (int i = 0; i < s.size(); i++)
		if (i == 0 || s[i] != ' ' || (s[i] == ' ' && s[i - 1] != ' '))
			res.push_back(s[i]);

	int start = 0, end = res.size();
	for (int i = 0; res[i] == ' '; i++)
		start++;
	for (int i = res.size() - 1; res[i] == ' '; i--)
		end--;
	for (int i = start; i < end; i++)
		putchar(res[i]);
	putchar('\n');

	return 0;
}