#include<bits/stdc++.h>
using namespace std;
bool check(char c)
{
	return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z';
}
int main()
{
	char s[300];
	bool flag = false;
	int i = 0,length,ans1 = 0,ans2 = 0,n;
	scanf("%d%s",&n,s);
	while (i < strlen(s))
	{
		if (s[i] == '(')
		{
			flag = true;
			i++;
			continue;
		}
		if (s[i] == ')')
		{
			flag = false;
			i++;
			continue;
		}
		if (s[i] == '_')
		{
			i++;
			continue;
		}
		if (flag)
		{
			ans2++;
			while (check(s[i]))
				i++;
		}
		else
		{
			length = 0;
			while (check(s[i]))
			{
				i++;
				length++;
			}
			ans1 = max(ans1,length);
		}
	}
	printf("%d %d",ans1,ans2);
	return 0;
}