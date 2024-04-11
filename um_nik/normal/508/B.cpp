#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

int n;
string s;


int main()
{
	cin >> s;
	n = s.length();
	int idx = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if ((int)(s[i] - '0') % 2 == 1) continue;
		if (s[i] < s[n - 1])
		{
			swap(s[i], s[n - 1]);
			cout << s << endl;
			return 0;
		}
		idx = i;
	}
	if (idx == -1)
		cout << idx << endl;
	else
	{
		swap(s[idx], s[n - 1]);
		cout << s << endl;
	}

	return 0;
}