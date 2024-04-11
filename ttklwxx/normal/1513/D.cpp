#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
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
int a[200005],pos[200005];
bool bi(int x,int y)
{
	return a[x]<a[y];
}
bool vis[200005];
signed main()
{
	int t,n,p,l,r,sth,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		p=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			vis[i]=false;
			pos[i]=i;
		}
		sort(pos+1,pos+n+1,bi);
		sth=0;
		ans=0;
		for(int gre=1;gre<=n;gre++)
		{
			int i=pos[gre];
			if(a[i]>p||vis[i])continue;
			l=1;
			for(int j=i-1;j>=1;j--)
			{
				if(vis[j])
				{
					l=j+1;
					break;
				}
				if(a[j]%a[i]!=0)
				{
					l=j+1;
					break;
				}
			}
			if(l>i)continue;
			r=n;
			for(int j=i+1;j<=n;j++)
			{
				if(vis[j-1])
				{
					r=j-1;
					break;
				}
				if(a[j]%a[i]!=0)
				{
					r=j-1;
					break;
				}
			}
			sth+=r-l;
			ans+=a[i]*(r-l);
			for(int k=l;k<=r-1;k++)vis[k]=true;
		}
		printf("%lld\n",ans+(n-1-sth)*p);
	}
	return 0;
}