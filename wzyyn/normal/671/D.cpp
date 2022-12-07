#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=300005;
struct edge{
	int to,next;
}e[N*2];
int ls[N],rs[N],v[N],p[N];
int dis[N],tg[N],fa[N];
int head[N],rt[N],vis[N];
int tot,n,m;
ll ans;
void pushdown(int x){
	if (!x) return;
	if (ls[x]){
		tg[ls[x]]+=tg[x];
		v[ls[x]]+=tg[x];
	}
	if (rs[x]){
		tg[rs[x]]+=tg[x];
		v[rs[x]]+=tg[x];
	}
	tg[x]=0;
}
int merge(int x,int y){
	if (!x||!y) return x+y;
	if (v[x]>v[y]) swap(x,y);
	pushdown(x);
	rs[x]=merge(rs[x],y);
	if (dis[rs[x]]>dis[ls[x]]) swap(ls[x],rs[x]);
	dis[x]=dis[rs[x]]+1;
	return x;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
} 
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs(e[i].to);
			rt[x]=merge(rt[x],rt[e[i].to]);
		}
	if (x==1) return;
	vis[x]=1;
	for (;vis[p[rt[x]]]&&rt[x];)
		rt[x]=merge(ls[rt[x]],rs[rt[x]]);
	if (!rt[x]){
		puts("-1");
		exit(0);
	}
	ans+=v[rt[x]];
	tg[rt[x]]-=v[rt[x]];
	v[rt[x]]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	For(i,1,m){
		int x;
		scanf("%d%d%d",&x,&p[i],&v[i]);
		rt[x]=merge(rt[x],i);
	}
	dfs(1);
	printf("%lld\n",ans);
}