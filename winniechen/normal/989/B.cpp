#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 2005
char s[N];int n,p;
int main()
{
	scanf("%d%d",&n,&p);
	scanf("%s",s+1);
	for(int i=1;i<=n-p;i++)
	{
		if(s[i]=='.'||s[i+p]=='.'||s[i]!=s[i+p])
		{
			if(s[i]=='.'&&s[i+p]=='.')s[i]='1',s[i+p]='0';
			else if(s[i]=='.')s[i]='1'-s[i+p]+'0';
			else if(s[i+p]=='.')s[i+p]='1'-s[i]+'0';
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='.')printf("1");
				else printf("%c",s[i]);
			}
			puts("");
			return 0;
		}
	}
	puts("No");
	return 0;
}