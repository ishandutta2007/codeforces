#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
char s[202020];
int n;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for(int i = 1; i <= n; i++)
		s[i + n] = s[i];
	int now = 1, ans = 1;
	for(int i = 2; i <= 2 * n; i++)
	{
		if(s[i] != s[i - 1])
			now++;
		else
			now = 1;
		if(now > ans)
			ans = now;
	}
	if(ans > n)
		ans = n;
	printf("%d\n", ans);
	return 0;
}