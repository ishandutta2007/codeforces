#include<iostream>
#include<cstdio>
#include<map>
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
map<int,int>ma;
int a[200005];
signed main()
{
	int t,n,x,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		x=read();
		ma.clear();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			ma[a[i]]++;
		}
		sort(a+1,a+n+1);
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i>1&&a[i]==a[i-1])continue;
			if(ma[a[i]]<=ma[a[i]*x])
			{
				ma[a[i]*x]-=ma[a[i]];
				continue;
			}
			ans+=ma[a[i]]-ma[a[i]*x];
			ma[a[i]*x]=0;
		}
		//for(int i=1;i<=n;i++)ma[a[i]]=0;
		printf("%lld\n",ans); 
	}
	return 0;
}