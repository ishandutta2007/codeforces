#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[2005],ans[2005],top;
bool flag[1005],tmp[1005];
int mex()
{
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=n;i++)tmp[a[i]]=1;
	int ans=0;
	while(tmp[ans])ans++;
	return ans;
}
bool check()
{
	for(int i=1;i<=n;i++)
	  if(a[i]!=i-1)return 0;
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		top=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[a[i]])
			{
				ans[++top]=i;
				a[i]=mex();
			}
			flag[a[i]]=1;
		}
		int now=0;
		while(flag[now])now++;
		while(now!=n)
		{
			ans[++top]=now+1;
			int v=a[now+1];
			a[now+1]=now;
			now=v;
		}
		while(!check())
		{
			now=1;
			while(a[now]==now-1)now++;
			ans[++top]=now;
			int v=a[now];
			a[now]=n;
			now=v;
			while(now!=n)
			{
				ans[++top]=now+1;
				int v=a[now+1];
				a[now+1]=now;
				now=v;
			}
		}
		printf("%d\n",top);
		for(int i=1;i<=top;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}