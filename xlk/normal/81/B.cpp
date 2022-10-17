#include <bits/stdc++.h>
using namespace std;
int main()
{
	char s[512];
	char t[512];
	gets(s);
	int n = strlen(s);
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (isdigit(s[i]))
		{
			t[m++] = s[i];
		}
		else if (s[i] == ' ')
		{
			if (m > 0 && t[m - 1] != ' ' && t[m - 1] != '.')
			{
				t[m++] = s[i];
			}
		}
		else if (s[i] == ',')
		{
			while (m > 0 && t[m - 1] == ' ')
			{
				if (m > 1 && t[m - 2] == ',')
				{
					break;
				}
				m--;
			}
			t[m++] = s[i];
			t[m++] = ' ';
		}
		else if (s[i] == '.')
		{
			if (m > 0 && t[m - 1] != ' ')
			{
				t[m++] = ' ';
			}
			t[m++] = s[i++];
			t[m++] = s[i++];
			t[m++] = s[i];
		}
	}
	while (m > 0 && t[m - 1] == ' ')
	{
		m--;
	}
	t[m] = 0;
	puts(t);
	return 0;
}