#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> s;
		int x = 0, y = s.size() - 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '1')
			{
				x = i;
			}
			if (s[i] == '0')
			{
				y = i;
				break;
			}
		}
		printf("%d\n", y - x + 1);
	}
	return 0;
}