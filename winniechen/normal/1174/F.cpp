#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 200005
struct node{int to,next;}e[N<<1];
int fa[N],anc[N],siz[N],son[N],head[N],dep[N],sson[N],idx[N],tims,p[N],cnt,n;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x,int from)
{
	fa[x]=from,dep[x]=dep[from]+1,siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],siz[son[x]]<siz[to1]?son[x]=to1:0;
	}
}
void dfs2(int x,int top)
{
	anc[x]=top;idx[x]=++tims;p[tims]=x;if(son[x])dfs2(son[x],top),sson[x]=sson[son[x]];else sson[x]=x;
	for(int i=head[x];i!=-1;i=e[i].next)if(e[i].to!=fa[x]&&e[i].to!=son[x])dfs2(e[i].to,e[i].to);
}
int query(int op,int x){if(!op)cout<< "d "<< x << endl;else cout<<"s "<< x << endl;int ret;scanf("%d",&ret);return ret;}
void print(int x){cout<< "! "<< x << endl;exit(0);}
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs1(1,0),dfs2(1,1);
	int pos=1,d=query(0,1);
	while(1)
	{
		int td = query(0,sson[pos]);
		if(d+td==dep[sson[pos]]-dep[pos])print(p[idx[pos]+d]);
		int lst = (d+td-dep[sson[pos]]+dep[pos])>>1 , lca = p[idx[pos]+d-lst];
		pos = query(1,lca) , d = lst - 1;
	}
}