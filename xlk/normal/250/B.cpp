#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int a[8];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		memset(a, 0, sizeof a);
		cin >> s;
		int c = 0;
		for (int i = 0, j = 0; i < s.size(); i++)
		{
			if (s[i] == ':')
			{
				if (i > 0 && s[i - 1] == ':')
				{
					break;
				}
				a[j++] = c;
				c = 0;
			}
			else
			{
				if (isdigit(s[i]))
				{
					c = c * 16 + s[i] - '0';				
				}
				else
				{
					c = c * 16 + s[i] - 'a' + 10;
				}
			}
		}
		c = 0;
		int d = 1;
		for (int i = s.size() - 1, j = 7; i >= 0; i--)
		{
			if (s[i] == ':')
			{
				if (i + 1 < s.size() && s[i + 1] == ':')
				{
					break;
				}
				a[j--] = c;
				c = 0;
				d = 1;
			}
			else
			{
				if (isdigit(s[i]))
				{
					c += (s[i] - '0') * d;
				}
				else
				{
					c += (s[i] - 'a' + 10) * d;
				}
				d *= 16;
			}
		}
		for (int i = 0; i < 7; i++)
		{
			printf("%04x:", a[i]);
		}
		printf("%04x\n", a[7]);
	}
	return 0;
}