#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[300000];
int n,m;
int f[300000];
int c[300000];
void mk(int x)
{
	fe(i,a[x])
		if(f[*i]==-1)
		{
			f[*i]=x;
			mk(*i);
		}
}
void P(int x,int C)
{
	c[x]=C;
	fe(i,a[x])
		if(f[*i]==x)
			P(*i,C^1);
}
bool dfs1(int x)
{
	fe(i,a[x])
		if(f[*i]==x)
			if(!dfs1(*i))
				return false;
	if(f[x]!=-1)
	{
		int co=-1;
		fe(i,a[x])
			if(*i!=f[x])
			{
				if(co==-1)
					co=c[*i];
				if(co!=c[*i])
					co=-2;
			}
		if(co>=0)
			c[x]=co^1;
	}
	int cnt=0;
	fe(i,a[x])
		cnt+=c[x]==c[*i];
	return cnt<2;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	bool ans=true;
	memset(f,-1,sizeof(f));
	for(int i=0;i<n;++i)
		if(f[i]==-1)
		{
			f[i]=-2;
			mk(i);
			P(i,0);
			if(dfs1(i))
				continue;
			P(i,0);
			c[i]=1;
			if(dfs1(i))
				continue;
			ans=false;
			break;
		}
	if(!ans)
		return puts("-1"),0;
	for(int i=0;i<n;++i)
		putchar('0'+c[i]);
	puts("");
}