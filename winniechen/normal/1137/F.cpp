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
#define ls ch[rt][0]
#define rs ch[rt][1]
#define get(rt) (ch[f[rt]][0]!=rt)
#define isroot(rt) (ch[f[rt]][0]!=rt&&ch[f[rt]][1]!=rt)
int ch[N][2],siz[N],f[N],val[N],tag[N],c[N<<1],rev[N],n,Q,tot;
inline void PushUp(int rt){siz[rt]=siz[ls]+siz[rs]+1;}
inline void rotate(int rt)
{
	int x=f[rt],y=f[x],k=get(rt);
	if(!isroot(x))ch[y][ch[y][0]!=x]=rt;
	ch[x][k]=ch[rt][!k],f[ch[x][k]]=x;
	ch[rt][!k]=x,f[x]=rt,f[rt]=y;PushUp(x),PushUp(rt);
}
inline void giv(int rt,int v){if(rt)tag[rt]=val[rt]=v;}
inline void giv_rev(int rt){if(rt)swap(ls,rs),rev[rt]^=1;}
inline void PushDown(int rt){if(rev[rt])giv_rev(ls),giv_rev(rs),rev[rt]=0;if(tag[rt])giv(ls,tag[rt]),giv(rs,tag[rt]),tag[rt]=0;}
inline void Update(int rt){if(!isroot(rt))Update(f[rt]);PushDown(rt);}
inline void Splay(int rt){for(Update(rt);!isroot(rt);rotate(rt))if(!isroot(f[rt]))rotate((get(f[rt])==get(rt))?f[rt]:rt);}
inline void fix(int x,int v){if(x)for(;x<=tot;x+=x&-x)c[x]+=v;}
inline int find(int x){int ret=0;for(;x;x-=x&-x)ret+=c[x];return ret;}
inline void access(int rt,int v)
{
	for(int t=0;rt;PushUp(rt),t=rt,rt=f[rt])
		Splay(rt),rs=0,PushUp(rt),fix(val[rt],-siz[rt]),fix(v,siz[rt]),giv(rt,v),rs=t;
}
inline int query(int rt)
{
	Splay(rt);
	// printf("%d %d %d\n",rt,val[rt],siz[ls]);
	return find(val[rt])-siz[ls];
}
char opt[10];
struct node{int to,next;}e[N<<1];int head[N],cnt;
void add(int x,int y){e[cnt]=(node){y,head[x]};head[x]=cnt++;}
void dfs(int x,int from)
{
	val[x]=x;f[x]=from;siz[x]=1;
	for(int i=head[x];i!=-1;i=e[i].next)
	{
		int to1=e[i].to;
		if(to1!=from)dfs(to1,x),val[x]<val[to1]?val[x]=val[to1],ch[x][1]=to1:0;
	}PushUp(x),fix(val[x],1);
}
int main()
{
	scanf("%d%d",&n,&Q);tot=n+Q;int now=n;memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),add(x,y),add(y,x);dfs(n,0);
	while(Q--)
	{
		int x,y;
		scanf("%s%d",opt,&x);
		if(opt[0]=='u')access(x,++now),Splay(x),giv_rev(x);
		else if(opt[0]=='w')printf("%d\n",query(x));
		else 
		{
			scanf("%d",&y);
			printf("%d\n",query(x)<query(y)?x:y);
		}
		// for(int i=1;i<=n;i++)printf("%d ",query(i));puts("");
	}
}