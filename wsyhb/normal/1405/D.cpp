#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
const int E=2e5+5;
int End[E],Last[max_n],Next[E],e;
void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
}
int dep[max_n];
void dfs(int x,int fa,int &s)
{
	dep[x]=dep[fa]+1;
	if(dep[x]>dep[s]) s=x;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa) dfs(y,x,s);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,b,da,db;
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(int i=1;i<=n;++i) Last[i]=0;
		e=0;
		for(int i=1;i<n;++i)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			add_edge(x,y);
		}
		int s=0,t=0;
		dfs(a,0,s);
		if(dep[b]-1<=da)
		{
			printf("Alice\n");
			continue;
		}
		dfs(s,0,t);
		if((da<<1)>=dep[t]-1) printf("Alice\n");
		else if(db>(da<<1)) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}