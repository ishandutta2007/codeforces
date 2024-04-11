#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[10];
int main()
{
	while(scanf("%s", s + 1))
	{
		int len = strlen(s + 1);
		if(len == 3) break;
		printf("? 0 1\n");
		fflush(stdout);
		scanf("%s", s + 1);
		if(s[1] == 'x')
		{
			printf("! 1\n");
			fflush(stdout);
			continue;
		}
		int now = 1;
		while(now * 2 <= 1000000000)
		{
			printf("? %d %d\n", now, now * 2);
			fflush(stdout);
			scanf("%s", s + 1);
			if(s[1] == 'x') break;
			else now <<= 1;
		}
		int l = now, r = now * 2;
		r = min(r, 1000000000);
		while(l < r)
		{
			int mid = (l + r + 1) >> 1;
			printf("? %d %d\n", mid, mid * 2);
			fflush(stdout);
			scanf("%s", s + 1);
			if(s[1] == 'x') l = mid;
			else r = mid - 1;
		}
		printf("! %d\n", l);
		fflush(stdout);
	}
	return 0;
}