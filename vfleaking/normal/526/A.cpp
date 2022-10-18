#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100;

int main()
{
	int n;
	static char s[MaxN + 1];

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		for (int l = 1; i + l * 4 < n; l++)
		{
			if (s[i] == '*' && s[i + l] == '*' && s[i + l * 2] == '*' && s[i + l * 3] == '*' && s[i + l * 4] == '*')
			{
				cout << "yes" << endl;
				return 0;
			}
		}
	cout << "no" << endl;

	return 0;
}