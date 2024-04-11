#include<bits/stdc++.h>
int main()
{
	char s[110];
	scanf("%s", s);
	int max = 0, sit = -1;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] != 'A' && s[i] != 'E' && s[i] != 'I' && s[i] != 'U' && s[i] != 'O' && s[i] != 'Y')
			continue;
		if (max < i - sit)
			max = i - sit;
		sit = i;
	}
	if (strlen(s) - sit > max)
		max = strlen(s) - sit;
	printf("%d\n", max);
	return 0;
}