#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char s[2005];
int n;
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=2;i<=n;i++)
	{
		if(s[i]!=s[i-1])
		{
			printf("YES\n");
			printf("%c%c\n",s[i-1],s[i]);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}