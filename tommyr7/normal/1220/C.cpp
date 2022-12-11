#include <bits/stdc++.h>
using namespace std;
#define Maxn 500007
char s[Maxn];
int len;
int main()
{
	scanf("%s",s+1);
	len=strlen(s+1);
	printf("Mike\n");
	int mn=3007;
	for (int i=2;i<=len;i++)
	{
		mn=min(mn,(int)s[i-1]);
		if ((int)s[i]>mn) printf("Ann\n"); else printf("Mike\n");
	}
	return 0;
}