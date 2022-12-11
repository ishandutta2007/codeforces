#include <bits/stdc++.h>
using namespace std;

char s1[1005], s2[1005];
char swp[256];

int main()
{
	scanf("%s%s", s1, s2);
	int cnt = 0;
	for (int i = 0; s1[i]; i++)
	{
		if (swp[s1[i]] == 0 && swp[s2[i]] == 0)
		{
			swp[s1[i]] = s2[i];
			swp[s2[i]] = s1[i];
		}
		else if (swp[s1[i]] == 0)
		{
			printf("-1");
			return 0;
		}
		else if (swp[s1[i]] != s2[i] || swp[s2[i]] != s1[i])
		{
			printf("-1");
			return 0;
		}
	}
	for (int i = 'a'; i <= 'z'; i++) if (swp[i] && swp[i] != i && i < swp[i]) cnt++;
	printf("%d\n", cnt);
	for (int i = 'a'; i <= 'z'; i++) if (swp[i] && swp[i] != i && i < swp[i])
		printf("%c %c\n", i, swp[i]);
}