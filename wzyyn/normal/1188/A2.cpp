#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],deg[N],tot,n;
int dep[N],fa[N],fav[N];
int lf[N],lff[N],top,rt;
pii q[N];
struct node{
	int x,y,v;
}ans[N*5];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void adde(int x,int y,int v){
	ans[++top]=(node){x,y,v};
	for (;x!=y;){
		if (dep[x]<dep[y]) swap(x,y);
		fav[x]-=v; x=fa[x];
	}
}
void dfs1(int x){
	dep[x]=dep[fa[x]]+1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			fav[e[i].to]=e[i].v;
			dfs1(e[i].to);
			lf[x]=lf[e[i].to];
		}
	if (!lf[x]) lf[x]=x;
}
void dfs2(int x){
	if (deg[x]==1) return;
	int t=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x])
			q[++t]=pii(lf[e[i].to],fav[e[i].to]);
	if (fa[x]) q[++t]=pii(lff[x],fav[x]);
	For(i,1,t-1){
		adde(q[i].fi,q[i+1].fi,q[i].se);
		q[i+1].se-=q[i].se;
	}
	adde(q[t].fi,q[1].fi,q[t].se/2);
	adde(q[t].fi,q[2].fi,q[t].se/2);
	adde(q[1].fi,q[2].fi,-(q[t].se/2));
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			lff[e[i].to]=(q[1].fi==lf[e[i].to]?q[2].fi:q[1].fi);
			dfs2(e[i].to);
		}
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
		++deg[x]; ++deg[y];
	}
	For(i,1,n)
		if (deg[i]==2)
			return puts("NO"),0;
	if (n==2){
		printf("YES\n1\n1 2 %d\n",e[1].v);
		return 0;
	}
	For(i,1,n)
		if (deg[i]!=1) rt=i;
	dfs1(rt);
	dfs2(rt);
	puts("YES");
	printf("%d\n",top);
	For(i,1,top) printf("%d %d %d\n",ans[i].x,ans[i].y,ans[i].v);
}