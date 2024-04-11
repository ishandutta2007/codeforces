#include<iostream>
#include<cstdio>
#include<vector>
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
int a[200005],b[200005];
int ma[200005],mb[200005];
vector<int>v[200005],vb[200005];
signed main()
{
	int t,n,ans=0,sla=0,slb=0,tans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		sla=0;
		slb=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
			sla+=ma[a[i]];
			slb+=mb[b[i]];
			ma[a[i]]++;
			mb[b[i]]++;
			v[a[i]].push_back(i);
			vb[b[i]].push_back(i);
		}
		ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=(n-ma[a[i]]-mb[b[i]]+1)*(n-ma[a[i]]-mb[b[i]])/2;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<v[i].size();j++)
			{
				mb[b[v[i][j]]]--;
				slb-=mb[b[v[i][j]]];
			}
			for(int j=0;j<v[i].size();j++)
			{
				ans-=slb-mb[b[v[i][j]]]*(mb[b[v[i][j]]]-1)/2;
			}
			for(int j=0;j<v[i].size();j++)
			{
				slb+=mb[b[v[i][j]]];
				mb[b[v[i][j]]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<vb[i].size();j++)
			{
				ma[a[vb[i][j]]]--;
				sla-=ma[a[vb[i][j]]];
			}
			for(int j=0;j<vb[i].size();j++)
			{
				ans-=sla-ma[a[vb[i][j]]]*(ma[a[vb[i][j]]]-1)/2;
			}
			for(int j=0;j<vb[i].size();j++)
			{
				sla+=ma[a[vb[i][j]]];
				ma[a[vb[i][j]]]++;
			}
		}
		ans=ans/3;
		//printf("%lld\n",ans);
		tans=n*(n-1)*(n-2)/3-sla*(n-2)-slb*(n-2);
		for(int i=1;i<=n;i++)
		{
			tans+=ma[i]*(ma[i]-1)*(ma[i]-2)/3;
			tans+=mb[i]*(mb[i]-1)*(mb[i]-2)/3;
		}
		printf("%lld\n",tans-ans);
		for(int i=1;i<=n;i++)ma[i]=mb[i]=0,v[i].clear(),vb[i].clear();
	}
	return 0;
}