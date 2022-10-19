#include<iostream>
#include<cstdio>
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
int ans,zk;
int vis[10];
int sz[15];
bool dfs(int sth,int k)
{
	if(k>zk)return false;
	if(sth==0)
	{
		if(k<=zk)return true;
		return false;
	}
	if(vis[sz[sth]]==0)k++;
	vis[sz[sth]]++;
	ans=ans*10+sz[sth];
	if(dfs(sth-1,k)==true)return true;
	ans/=10;
	vis[sz[sth]]--;
	if(vis[sz[sth]]==0)k--;
	if(k!=zk)
	{
		if(vis[sz[sth]+1]==0)k++;
		vis[sz[sth]+1]++;
		ans=ans*10+sz[sth]+1;
		if(zk!=k)
		{
			for(int i=sth-1;i>=1;i--)ans=ans*10;
			return true;
		}
		int gre=0;
		for(int i=0;i<=9;i++)if(vis[i]!=0)
		{
			gre=i;
			break;
		}
		for(int i=sth-1;i>=1;i--)ans=ans*10+gre;
		return true;
	}
	int gre=-1;
	for(int i=sz[sth]+1;i<=9;i++)if(vis[i]!=0)
	{
		gre=i;
		break;
	}
	if(gre==-1)return false;
	ans=ans*10+gre;
	gre=-1;
	for(int i=0;i<=9;i++)if(vis[i]!=0)
	{
		gre=i;
		break;
	}
	for(int i=sth-1;i>=1;i--)ans=ans*10+gre;
	return true;
}
int main()
{
	int t,n,wsss,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		zk=read();
		wsss=0;
		sth=n;
		while(sth!=0)
		{
			wsss++;
			sz[wsss]=sth%10;
			sth/=10;
		}
		for(int i=0;i<=9;i++)vis[i]=0;
		ans=0;
		dfs(wsss,0);
		printf("%d\n",ans);
	}
	return 0;
}