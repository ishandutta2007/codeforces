#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m;
char s[105][105];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		bool f1=1,f2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='P')f1=0;
				if(s[i][j]=='A')f2=1;
			}
		}
		if(f1)
		{
			printf("0\n");
			continue;
		}
		if(!f2)
		{
			printf("MORTAL\n");
			continue;
		}
		f1=1;
		for(int i=1;i<=n;i++)
		  if(s[i][1]=='P')f1=0;
		if(f1)
		{
			printf("1\n");
			continue;
		}
		f1=1;
		for(int i=1;i<=n;i++)
		  if(s[i][1]=='P')f1=0;
		if(f1)
		{
			printf("1\n");
			continue;
		}
		f1=1;
		for(int i=1;i<=n;i++)
		  if(s[i][m]=='P')f1=0;
		if(f1)
		{
			printf("1\n");
			continue;
		}
		f1=1;
		for(int i=1;i<=m;i++)
		  if(s[1][i]=='P')f1=0;
		if(f1)
		{
			printf("1\n");
			continue;
		}
		f1=1;
		for(int i=1;i<=m;i++)
		  if(s[n][i]=='P')f1=0;
		if(f1)
		{
			printf("1\n");
			continue;
		}
		if(s[1][1]=='A'||s[1][m]=='A'||s[n][1]=='A'||s[n][m]=='A')
		{
			printf("2\n");
			continue;
		}
		f1=0;
		for(int i=1;i<=n;i++)
		{
			f2=1;
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='P')
				{
					f2=0;
					break;
				}
			}
			if(f2)
			{
				f1=1;
				break;
			}
		}
		if(f1)
		{
			printf("2\n");
			continue;
		}
		f1=0;
		for(int j=1;j<=m;j++)
		{
			f2=1;
			for(int i=1;i<=n;i++)
			{
				if(s[i][j]=='P')
				{
					f2=0;
					break;
				}
			}
			if(f2)
			{
				f1=1;
				break;
			}
		}
		if(f1)
		{
			printf("2\n");
			continue;
		}
		f1=0;
		for(int i=1;i<=n;i++)
		  if(s[i][1]=='A'||s[i][m]=='A')
		    f1=1;
		for(int i=1;i<=m;i++)
		  if(s[1][i]=='A'||s[n][i]=='A')
		    f1=1;
		if(f1)
		{
			printf("3\n");
			continue;
		}
		printf("4\n");
	}
	return 0;
}