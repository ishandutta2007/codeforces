#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 205
using namespace std;
int t, n;
char s[55];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1);
		for (int i = 1; i <= n; i++)
		{
			if(i & 1)
			{
				if(s[i] == 'a') printf("b");
				else printf("a");
			}
			else
			{
				if(s[i] == 'z') printf("y");
				else printf("z");
			}
		}
		printf("\n");
	}
	return 0;
}