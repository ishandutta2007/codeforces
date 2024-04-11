#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> ii;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
vector<int>a[100020];
vector<ii>b[100020];
queue<int>q;
int dfn[100020];
int low[100020];
int n,m,cnt,w;
int d[100020];
int s[100020],ss;
int r[100020],scc;
int v[100020];
int x[100020];
int y[100020];
int z[100020];
int xiaodao[100020];
void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	s[ss++]=x;
	v[x]=1;
	fe(i,a[x])
		if(!dfn[*i])
		{
			dfs(*i);
			low[x]=min(low[x],low[*i]);
		}
		else if(v[*i])
			low[x]=min(low[x],dfn[*i]);
	if(dfn[x]==low[x])
	{
		int u;
		do{
			u=s[--ss];
			r[u]=scc;
			v[u]=0;
		}
		while(u!=x);
		scc++;
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d%d%d",x+i,y+i,z+i);
	for(int i=0;i<m;i++)
		if(!z[i])
			a[x[i]].push_back(y[i]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(int i=0;i<m;i++)
		if(!z[i])
			i[y][r][d]++;
	for(int i=0;i<m;i++)
		if(!z[i]||z[i]&&!i[y][r][d])
			b[i[x][r]].push_back(ii(i[y][r],i));
	for(int i=0;i<scc;i++)
		if(r[1]!=i&&d[i]==0)
			w++;
	1[r][v]=1;
	q.push(r[1]);
	while(q.size())
	{
		int u=q.front();
		q.pop();
		fe(i,b[u])
			if(!v[i->X])
			{
				v[i->X]=1;
				xiaodao[i->Y]=1;
				q.push(i->X);
			}
	}
	for(int i=0;i<scc;i++)
		if(!v[i])
			return puts("-1"),0;
	printf("%d\n",w);
	for(int i=0;i<m;i++)
		if(z[i]&&xiaodao[i])
			printf("%d ",i+1);
	return 0;
}