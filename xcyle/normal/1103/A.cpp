#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1005
using namespace std;
int n;
char s[maxn];
int now = 0, now2 = 0;
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
	{
		if(s[i] == '0')
		{
			printf("3 %d\n", ++now);
			now %= 4;
		}
		if(s[i] == '1')
		{
			printf("1 %d\n", (++now2) * 2 - 1);
			now2 %= 2;
		}
	} 
	return 0;
}