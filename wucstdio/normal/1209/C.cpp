#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,top[10],st[10][200005],ans[200005];
char s[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=0;i<10;i++)top[i]=0;
		for(int i=1;i<=n;i++)st[s[i]-'0'][++top[s[i]-'0']]=i;
		int last=0;
		for(int i=0;i<10;i++)
		{
			if(!top[i])continue;
			if(last<st[i][1])
			{
				for(int j=1;j<=top[i];j++)
				  ans[st[i][j]]=ans[last];
				last=st[i][top[i]];
			}
			else
			{
				int v=ans[last];
				int tt=last;
				for(int j=1;j<=top[i];j++)
				{
					if(st[i][j]<tt)ans[st[i][j]]=v+1,last=st[i][j];
					else ans[st[i][j]]=v;
				}
			}
		}
		if(ans[last]>1)printf("-\n");
		else
		{
			for(int i=1;i<=n;i++)printf("%d",ans[i]+1);
			printf("\n");
		}
	}
	return 0;
}