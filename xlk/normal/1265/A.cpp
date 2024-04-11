#include <bits/stdc++.h>
using namespace std;
int t;
char s[100020];
void gao()
{
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '?')
		{
			s[i] = 'a';
			while (s[i] == s[i - 1] || s[i] == s[i + 1])
			{
				s[i]++;
			}
		}
		if (s[i] == s[i + 1])
		{
			printf("-1\n");
			return;
		}
	}
	printf("%s\n", s + 1);
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%s", s + 1);
		gao();
	}
	return 0;
}