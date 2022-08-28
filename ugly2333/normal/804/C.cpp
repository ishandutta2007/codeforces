//CF 804C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
int s[333333],c[333333],f[333333];
vector<int> v[333333],g[333333];
void dfs(int u,int fa)
{
	int i,j;
	for(i=0;i<s[u];i=i+1)
		f[c[v[u][i]]]=1;
	j=1;
	for(i=0;i<s[u];)
	{
		if(!f[j]){
			if(!c[v[u][i]]){
				c[v[u][i]]=j;
				j=j+1;
			}
			i=i+1;
		}
		else
			j=j+1;
	}
	for(i=0;i<s[u];i=i+1)
		f[c[v[u][i]]]=0;
	for(i=0;i<g[u].size();i=i+1)
		if(g[u][i]!=fa)
			dfs(g[u][i],u);
}
int main()
{
	int n,m,i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		scanf("%d",&s[i]);
		for(j=1;j<=s[i];j=j+1){
			scanf("%d",&x);
			v[i].push_back(x);
		}
	}
	for(i=1;i<n;i=i+1)
	{
		scanf("%d%d",&j,&x);
		g[j].push_back(x);
		g[x].push_back(j);
	}
	dfs(1,0);
	x=0;
	for(i=1;i<=m;i=i+1){
		if(c[i]==0)
			c[i]=1;
		x=max(x,c[i]);
	}
	printf("%d\n",x);
	for(i=1;i<=m;i=i+1)
		printf("%d ",c[i]);
	/*for(i=1;i<=n;i=i+1){
		for(j=1;j<=s[i];j=j+1)
			cout<<c[v[i][j-1]]<<' ';
		cout<<"\n";
	}*/
	printf("\n");
	return 0;
}
/*
3 3
0
0
0
1 2
3 2

*/