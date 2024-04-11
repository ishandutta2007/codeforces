#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

bool used[11];
string s;

void No()
{
	cout << "NO" << endl;
}
void Yes()
{
	cout << "YES" << endl;
}

int main()
{
	cin >> s;
	cin >> s;
	for (int i = 0; i < (int)s.length(); i++)
		used[(int)(s[i] - '0')] = 1;
	if (!used[1] && !used[2] && !used[3])
	{
		No();
		return 0;
	}
	if (used[0])
	{
		Yes();
		return 0;
	}
	if (!used[7] && !used[9])
	{
		No();
		return 0;
	}
	if (!used[1] && !used[4] && !used[7])
	{
		No();
		return 0;
	}
	if (!used[3] && !used[6] && !used[9])
	{
		No();
		return 0;
	}
	Yes();
	return 0;
}