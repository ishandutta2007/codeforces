#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
using namespace std;
#define N 500005
struct node{int to,next;}e[N<<1];
int head[N],siz[N],cnt,n,S[1<<23],val[N],son[N],dep[N],ans[N],tmp_ans;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs1(int x,int from)
{
	dep[x]=dep[from]+1,siz[x]=1,val[x]^=val[from];
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs1(to1,x),siz[x]+=siz[to1],son[x]=(siz[to1]>siz[son[x]]?to1:son[x]);
	}
}
#define change(x) S[val[x]]=max(dep[x],S[val[x]]);
void add(int x,int from,bool op)
{
	if(op)S[val[x]]=max(dep[x],S[val[x]]);
	else S[val[x]]=-0x3f3f3f3f;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)add(to1,x,op);
	}
}
void get(int x)
{
	tmp_ans=max(tmp_ans,S[val[x]]+dep[x]);
	for(int i=0;i<=22;i++)tmp_ans=max(tmp_ans,S[val[x]^(1<<i)]+dep[x]);
}
void get_ans(int x,int from)
{
	get(x);
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)get_ans(to1,x);
	}
}
void dfs2(int x,int from,int op)
{
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from&&to1!=son[x])dfs2(to1,x,0);
	}if(son[x])dfs2(son[x],x,1),ans[x]=ans[son[x]];
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from&&to1!=son[x])
			get_ans(to1,x),ans[x]=max(ans[x],ans[to1]),add(to1,x,1);
	}get(x);change(x);
	// printf("%d\n",x);
	// for(int i=1;i<(1<<23);i++)if(S[i]>0)printf("%d ",i);puts("");
	ans[x]=max(ans[x],tmp_ans-(dep[x]<<1)),tmp_ans=0;
	if(!op)add(x,from,0);
}char rr[3];
int main()
{
	scanf("%d",&n);memset(head,-1,sizeof(head));memset(S,-0x3f,sizeof(S));
	for(int i=2,x;i<=n;i++)scanf("%d%s",&x,rr),val[i]=1<<(rr[0]-'a'),add(x,i),add(i,x);
	dfs1(1,0);dfs2(1,0,1);for(int i=1;i<=n;i++)printf("%d ",ans[i]);return 0;
}