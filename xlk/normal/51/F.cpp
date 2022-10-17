#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
vector<int>a[2020],e[2020];
int n,m,dfn[2020],low[2020],r[2020],s[2020],ss,cnt,bcc,x,y,z,d,c;
void dfs(int x,int y)
{
	dfn[x]=low[x]=++cnt;
	s[ss++]=x;
	for(int i:a[x])
		if(i!=y)
		{
			if(!dfn[i])
				dfs(i,x),low[x]=min(low[x],low[i]);
			else
				low[x]=min(low[x],dfn[i]);
		}
	if(dfn[x]==low[x])
	{
		bcc++;
		do
			r[s[--ss]]=bcc;
		while(s[ss]!=x);
	}
}
int F(int x,int y)
{
	dfn[x]=1;
	c+=e[x].size()<2;
	int u=0,v=0,w;
	for(int i:e[x])
		if(i!=y)
		{
			w=F(i,x);
			if(w>u)
				v=u,u=w;
			else if(w>v)
				v=w;
		}
	d=max(d,u+v);
	return u+1;
}
int main()
{
	for(cin>>n>>m;m--;)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i,0);
	for(int i=1;i<=n;i++)
		for(int j:a[i])
			if(r[i]!=r[j])
				e[r[i]].push_back(r[j]);
	memset(dfn,0,sizeof dfn);
	z=n-1;
	for(int i=1;i<=bcc;i++)
		if(!dfn[i])
		{
			d=c=0;
			F(i,0);
			if(c>1)
				z-=d+c-2;
		}
	cout<<z;
	return 0;
}