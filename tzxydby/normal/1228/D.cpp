#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>e[N];
int co[N],x,y;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(!e[1].size())
	{
		puts("-1");
		return 0;
	}
	co[1]=1;
	x=e[1][0];
	co[x]=2;
	for(int i=2;i<=n;i++)
	{
		if(i==x)
			continue;
		int flag1=0,flag2=0;
		for(auto j:e[i])
		{
			if(j==1)
				flag1=1;
			if(j==x)
				flag2=1;
		}
		if(flag1&&flag2)
		{
			y=i;
			co[y]=3;
			break;
		}
	}
	if(!y)
	{
		puts("-1");
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(i==x||i==y)
			continue;
		int f1=0,f2=0,f3=0;
		for(auto j:e[i])
		{
			if(j==1)
				f1=1;
			if(j==x)
				f2=1;
			if(j==y)
				f3=1;
		}
		if(f1+f2+f3!=2)
		{
			puts("-1");
			return 0;
		}
		if(!f1)
			co[i]=1;
		if(!f2)
			co[i]=2;
		if(!f3)
			co[i]=3;
	}
	int s[4]={};
	for(int i=1;i<=n;i++)
		s[co[i]]++;
	if(s[1]*s[2]+s[2]*s[3]+s[1]*s[3]!=m)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:e[i])
		{
			if(co[i]==co[j])
			{
				puts("-1");
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++)
		printf("%d ",co[i]);
	puts(""); 
	return 0;
}