#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 100005
struct node{int to,next;}e[N<<1];
int n,m,fa[N],siz[N],head[N],cnt,in1[N];vector<int>v[N];
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;in1[y]++;}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void uni(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return ;
	if(siz[x]<siz[y])swap(x,y);
	fa[y]=x;siz[x]+=siz[y];
	for(int i=0;i<v[y].size();i++)v[x].push_back(v[y][i]);
}
int tsort(int S)
{
	queue<int>q;
	for(int i=0;i<v[S].size();i++)if(!in1[v[S][i]])q.push(v[S][i]);
	int num=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();num++;
		for(int i=head[x];i!=-1;i=e[i].next)
		{
			int to1=e[i].to;
			if(!(--in1[to1]))q.push(to1);
		}
	}
	return v[S].size()-(num==v[S].size());
}
int main()
{
	// freopen("b.in","r",stdin);
	// freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);int ans=0;memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1,v[i].push_back(i);
	for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),add(x,y),uni(x,y);
	for(int i=1;i<=n;i++)if(find(i)==i)ans+=tsort(i);
	printf("%d\n",ans);
}
/*
4 6
1 2
1 4
2 3
2 4
3 2
3 4
 */