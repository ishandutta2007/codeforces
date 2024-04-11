#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[200005];
int b[200005],cnt;
bool vis[200005];
signed main()
{
	int t,n,ans=0,x;
	bool flag; 
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n+1;i++)vis[i]=false;
		cnt=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<=n&&vis[a[i]]==false)
			{
				vis[a[i]]=true;
			}
			else b[++cnt]=a[i];
		}
		sort(b+1,b+cnt+1);
		flag=true;
		ans=0;
		x=0;
		for(int i=1;i<=cnt;i++)
		{
			x++;
			while(vis[x]==true)x++;
			if(b[i]==x)continue;
			if(b[i]<=2*x)
			{
				flag=false;
				break;
			}
			ans++;
		}
		if(flag==false)printf("-1\n");
		else printf("%d\n",ans);
	} 
	return 0;
}