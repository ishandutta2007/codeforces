#include <bits/stdc++.h>
using namespace std;
int t;
char s[100020];
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%s", s + 1);
		int n = strlen(s + 1);
		int z = 0;
		for (int i = 2; i <= n; i++)
		{
			if (s[i] == s[i - 1] || s[i] == s[i - 2])
			{
				s[i] = '?';
				z++;
			}
		}
		printf("%d\n", z);
	}
	return 0;
}