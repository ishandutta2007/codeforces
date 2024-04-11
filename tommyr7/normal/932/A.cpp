#include <bits/stdc++.h>
#define Maxn 1007
using namespace std;
char s[Maxn];
int len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	for (int i=1;i<=len;i++)
		printf("%c",s[i]);
	for (int i=len;i;i--)
		printf("%c",s[i]);
	printf("\n");
	return 0;
}