#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, k;
char s[202020];

int main()
{
	scanf("%d%d", &n, &k);
	scanf("%s", s + 1);
	int cnt = 0;
	int now = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '(')
		{
			if(cnt + now < k)
				printf("("), cnt++, now++;
		}
		else
		{
			if(now > 0)
				printf(")"), cnt++, now--;
		}
	}
	return 0;
}