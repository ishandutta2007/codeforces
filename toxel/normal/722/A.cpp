#include<bits/stdc++.h>
int main()
{
	int n;
	char s[10];
	scanf("%d%s",&n,s);
	if (n == 12)
	{
		if (s[0] > '1' || s[0] == '1' && s[1] > '2')
		{
			if (s[1] == '0')
				s[0] = '1';
			else
				s[0] = '0';
		}
		else if (s[0] == '0' && s[1] == '0')
			s[0] = '1';
	}
	else
	{
		if (s[0] > '2' || s[0] == '2' && s[1] >= '4')
			s[0] = '0';
	}
	if (s[3] >= '6')
		s[3] = '0';
	printf("%s",s);
	return 0;
}