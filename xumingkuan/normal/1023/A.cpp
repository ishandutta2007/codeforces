#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int MAXN = 202020;
char s[MAXN], t[MAXN];

int main()
{
	scanf("%d%d%s%s", &n, &m, s + 1, t + 1);
	if(n >= m + 2)
	{
		printf("NO\n");
		return 0;
	}
	int l = 1, r = n;
	s[n + 1] = '#';
	while(l <= r)
	{
		if(s[l] == '*')
		{
			l--;
			break;
		}
		if(s[l] != t[l])
		{
			printf("NO\n");
			return 0;
		}
		l++;
	}
	if(l > r)
	{
		if(n == m)
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	while(r > l + 1)
	{
		if(s[r] != t[r - n + m])
		{
			printf("NO\n");
			return 0;
		}
		r--;
	}
	printf("YES\n");
	return 0;
}