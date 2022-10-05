#include<bits/stdc++.h>
int main()
{
	char s[110], c[110] = "CODEFORCES";
	scanf("%s", s);
	int len = strlen(s);
	int i = 0;
	while (s[i] == c[i] && i < 10)
		i++;
	int j = 0;
	while (s[len - 1 - j] == c[9 - j])
		j++;
	if (i + j >= 10)
		return printf("YES"), 0;
	return printf("NO"), 0;
}