#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define mod 998244353
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
struct sth
{
	int x,y;
}a[200005];
bool bi(struct sth c,struct sth d)
{
	return c.y<d.y;
}
bool vis[200005];
vector<int>v,cnts;
int main()
{
	int t,n,s;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		s=read();
		for(int i=1;i<=n;i++)vis[i]=false;
		for(int i=1;i<=n;i++)
		{
			a[i].x=read();
		}
		for(int i=1;i<=n;i++)
		{
			a[i].y=read();
			if(a[i].y!=-1)vis[a[i].y]=true;
		}
		v.clear();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==false)v.push_back(i);
		}
		sort(a+1,a+n+1,bi);
		int maxn=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].y!=-1)
			{
				maxn=max(maxn,a[i].x-a[i].y);
			}
		}
		if(maxn>s)
		{
			printf("0\n");
			continue;
		}
		cnts.clear();
		for(int i=1;i<=n;i++)
		{
			if(a[i].y==-1)cnts.push_back(v.end()-lower_bound(v.begin(),v.end(),a[i].x-s));
		}
		sort(cnts.begin(),cnts.end());
		int ans=1;
		for(int i=0;i<cnts.size();i++)ans=1LL*ans*(cnts[i]-i)%mod;
		printf("%d\n",ans); 
	}
	return 0;
}