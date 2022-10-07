#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t;
char s[1005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s+1);
		int n=(int)strlen(s+1);
		int ans=0;
		for(int i=1;i<=n;i++)
		  if(s[i]!='0')ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0')continue;
			putchar(s[i]);
			for(int j=i+1;j<=n;j++)putchar('0');
			putchar(' ');
		}
		printf("\n");
	}
	return 0;
}