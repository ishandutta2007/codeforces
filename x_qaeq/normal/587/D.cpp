//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int N=300005<<2;struct edge{int to,nxt;}e[6000005];int Et,Head[N],tot;
struct node{int u,v,c,w,id;char operator<(node b) const {return c<b.c;}}ed[N],a[N];
int n,m,et,head[N],dfn[N],low[N],dt,tp,st[N],cl[N],ct;char vis[N];vector<node>eg[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,vis[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[x],low[e[i].to]);
		else if(vis[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y;++ct;do vis[y=st[tp--]]=0,cl[y]=ct;while(y!=x);}
}
inline void posbld(int n,node *a)
{
	int l0,l1,x0,x1,s0,s1;for(int i=1;i<=n;i++,l0=s0,l1=s1)
	{
		x0=a[i].id+m,x1=a[i].id,s0=++tot,s1=++tot,adde(x1,s1),adde(s0,x0);
		if(i^1) adde(x1,l0),adde(l1,x0),adde(s0,l0),adde(l1,s1);
	}
}
inline void negbld(int n,node *a)
{
	int l0,l1,x0,x1,s0,s1;for(int i=1;i<=n;i++,l0=s0,l1=s1)
	{
		x0=a[i].id+m,x1=a[i].id,s0=++tot,s1=++tot,adde(s1,x1),adde(x0,s0);
		if(i^1) adde(l0,x1),adde(x0,l1),adde(l0,s0),adde(s1,l1);
	}
}
inline char chk(int x)
{
	Et=et;for(int i=1;i<=m;i++) Head[i]=head[i];
	ct=dt=0;for(int i=1;i<=tot;i++) dfn[i]=vis[i]=0;
	for(int i=1;i<=m;i++) if(ed[i].w>x) adde(i,i+m);
	for(int i=1;i<=tot;i++) if(!dfn[i]) tarjan(i);
	et=Et;for(int i=1;i<=m;i++) head[i]=Head[i];
	for(int i=1;i<=m;i++) if(cl[i]==cl[i+m]) return 0;
	return 1;
}
int main()
{
	read(n),read(m),tot=m<<1;int le=0,ri=0,rs=0;
	for(int i=1;i<=m;i++)
	{
		read(ed[i].u),read(ed[i].v),read(ed[i].c),read(ed[i].w),ed[i].id=i;
		eg[ed[i].u].push_back(ed[i]),eg[ed[i].v].push_back(ed[i]),ri=max(ri,ed[i].w);
	}
	for(int i=1;i<=n;i++)
	{
		sort(eg[i].begin(),eg[i].end());int k=0;
		for(int j=0;j<(int)eg[i].size();j++) a[++k]=eg[i][j];
		posbld(k,a);for(int l=1,r=1;l<=k;l=++r)
		{
			while(r+1<=k&&a[l].c==a[r+1].c) r++;
			negbld(r-l+1,a+l-1);
		}
	}
	if(!chk(ri)) return puts("No"),0;else puts("Yes");
	while(le<=ri) {int md=(le+ri)>>1;if(chk(md)) ri=md-1,rs=md;else le=md+1;}
	chk(rs);int k=0;for(int i=1;i<=m;i++) if(cl[i]<cl[i+m]) st[++k]=i;
	printf("%d %d\n",rs,k);for(int i=1;i<=k;i++) printf("%d%c",st[i],i==k?'\n':' ');
	return 0;
}