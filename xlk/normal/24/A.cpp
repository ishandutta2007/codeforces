#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
vector<ii>a[120];
vector<int>q;
int g[120][120];
int v[120];
int n,x,y,z,S,T;
void dfs(int x)
{
	if(v[x])
		return;
	v[x]=1;
	q.push_back(x);
	if(!v[a[x][0].first])
		dfs(a[x][0].first);
	if(!v[a[x][1].first])
		dfs(a[x][1].first);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);	
		g[y][x]=z;
		a[x].push_back(ii(y,0));
		a[y].push_back(ii(x,z));
	}
	dfs(1);
	q.push_back(q[0]);
	for(int i=1;i<q.size();i++)
	{
		S+=g[q[i-1]][q[i]];
		T+=g[q[i]][q[i-1]];
	}
	printf("%d\n",min(S,T));
}