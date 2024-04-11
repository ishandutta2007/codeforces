#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100;

int main()
{
	string s;

	cin >> s;
	for (int i = 0; i < (int)s.size(); i++)
		for (int j = i; j < (int)s.size(); j++)
			if (s.substr(0, i) + s.substr(j + 1, (int)s.size() - j - 1) == "CODEFORCES")
			{
				puts("YES");
				return 0;
			}
	puts("NO");
	return 0;
}