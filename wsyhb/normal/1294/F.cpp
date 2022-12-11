#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,M=4e5+5;
int End[M],Last[N],Next[M],dep[N],f[N],id1[N],id2[N],id[N];
int cnt,mx,s1,s2,m1,m2;
void add(int x,int y)
{
	End[++cnt]=y;
	Next[cnt]=Last[x];
	Last[x]=cnt;
}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=fa;
	if(dep[x]>mx)
	{
		mx=dep[x];
		s1=x;
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa) dfs(y,x);
	}
}
void dfs1(int x,int fa)
{
	if(!fa) dep[x]=0;
	else dep[x]=dep[fa]+1;
	if(dep[x]>mx&&x!=m1&&x!=m2)
	{
		mx=dep[x];
		s1=x;
	}
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa&&y!=id1[x]&&y!=id2[x]) dfs1(y,x);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y),add(y,x);
	}
	dfs(1,0);
	mx=0;
	s2=s1;
	dfs(s2,0);
	int ans=mx,t=s1,la=0,cnt=0;
	while(t)
	{
		id[++cnt]=t;
		id1[t]=la;
		id2[t]=f[t];
		la=t;
		t=f[t];
	}
	mx=-1;
	t=s1;
	m1=id[1],m2=id[cnt];
	for(int i=1;i<=cnt;i++) dfs1(id[i],0);
	printf("%d\n%d %d %d\n",ans+mx-1,t,s2,s1);
	return 0;
}