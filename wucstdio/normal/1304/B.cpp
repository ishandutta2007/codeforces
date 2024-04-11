#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,ans,st[105],top;
char s[105][105];
bool used[105];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	{
		if(used[i])continue;
		bool found=0;
		for(int j=i+1;j<=n;j++)
		{
			if(used[j])continue;
			bool f=1;
			for(int k=1;k<=m;k++)
			  if(s[i][k]!=s[j][k])
			    f=0;
			if(f)
			{
				used[j]=1;
				found=1;
				break;
			}
			f=1;
			for(int k=1;k<=m;k++)
			  if(s[i][k]!=s[j][m-k+1])
			    f=0;
			if(f)
			{
				used[j]=1;
				found=1;
				break;
			}
		}
		if(found)
		{
			used[i]=1;
			st[++top]=i;
			ans+=2;
		}
	}
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(used[i])continue;
		bool f=1;
		for(int k=1;k<=m;k++)
		  if(s[i][k]!=s[i][m-k+1])
		    f=0;
		if(f)
		{
			ans++;
			x=i;
			break;
		}
	}
	printf("%d\n",ans*m);
	for(int i=1;i<=top;i++)printf("%s",s[st[i]]+1);
	if(x)printf("%s",s[x]+1);
	for(int i=top;i>=1;i--)
	{
		for(int j=m;j>=1;j--)
		  putchar(s[st[i]][j]);
	}
	putchar('\n');
	return 0;
}