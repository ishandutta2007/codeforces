#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
char s[202020];
int cnt[30];
int main()
{
	scanf("%d%s", &n, s + 1);
	if(n == 1)
	{
		printf("Yes\n");
		return 0;
	}
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= n; i++)
		cnt[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
		if(cnt[i] > 1)
		{
			printf("Yes\n");
			return 0;
		}
	printf("No\n");
	return 0;
}