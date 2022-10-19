#include<iostream>
#include<cstdio>
#include<cmath>
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
int p[200001],c[200001];
bool vis[200001];
int h[200001],cnt;
int ans=1000000000,tans;
bool check(int x)
{
	bool flag=false;
	for(int i=1;i<=x;i++)
	{
		flag=false;
		for(int j=1;j<cnt/x;j++)
		{
			if(c[h[j*x+i]]!=c[h[i]])
			{
				flag=true;
				break;
			}
		}
		if(flag==false)return true;
	}
	return false;
}
void dfs(int x)
{
	vis[x]=true;
	if(vis[p[x]])
	{
		tans=1000000000;
		cnt=0;
		int y=p[x];
		while(y!=x)
		{
			h[++cnt]=y;
			y=p[y];
		}
		h[++cnt]=x;
		for(int i=1;i<=sqrt(cnt);i++)
		{
			if(cnt%i!=0)continue;
			if(check(i))tans=min(tans,i);
			if(check(cnt/i))tans=min(tans,cnt/i);
		}
		ans=min(ans,tans);
		return;
    }
    dfs(p[x]);
}
signed main()
{
	int t,n;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int j=1;j<=n;j++)p[j]=read();
		for(int j=1;j<=n;j++)c[j]=read();
		ans=1000000000;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j])dfs(j);
		}
		for(int j=1;j<=n;j++)vis[j]=0;
		printf("%d\n",ans);
	}
	return 0;
}