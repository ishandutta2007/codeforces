#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,a[N][N][N],d[N][N],vis[N],c,fl,tg,t;
char s[N];
vector<int>e[N];
void dfs(int u,int f)
{
	if(vis[u]) fl=0;
	if(!fl) return;
	c++;
	vis[u]=1;
	e[u].push_back(f);
	e[f].push_back(u);
	for(int v=1;v<=n;v++)
	{
		if(!fl)
			return;
		if(v==u||v==f)
			continue;
		if(a[v][f][u]) 
		{
			if(vis[v])
				fl=0;
			else
				dfs(v,u);
		}
	}
}
void cal(int u,int f,int b,int ds)
{
	d[b][u]=ds;
	for(auto v:e[u])
		if(v!=f)
			cal(v,u,b,ds+1);
}
void chk(int bu,int bv)
{
	fl=1,c=0,t=0;
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		vis[i]=0;
	}
	for(int i=1;i<=n;i++)
		if(a[bu][bv][i])
			return;
	dfs(bu,bv);
	dfs(bv,bu);
	if(!fl)
		return;
	if(c!=n)
		return;
	for(int i=1;i<=n;i++)
	{
		sort(e[i].begin(),e[i].end());
		e[i].erase(unique(e[i].begin(),e[i].end()),e[i].end());
		for(auto j:e[i])
			t+=(i<j);
	}
	if(t!=n-1)
		return;
	for(int i=1;i<=n;i++)
		cal(i,i,i,0);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(a[i][j][k]!=(d[i][k]==d[j][k]))
					return;
	tg=0;
	puts("Yes");
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(d[i][j]==1)
				printf("%d %d\n",i,j);
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				a[i][j][k]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			scanf("%s",s+1);
			for(int k=1;k<=n;k++)
				a[i][j][k]=s[k]-'0',a[j][i][k]=a[i][j][k];
		}
	}
	tg=1;
	for(int i=2;i<=n&&tg;i++)
		chk(1,i);
	if(tg)
		puts("No");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}