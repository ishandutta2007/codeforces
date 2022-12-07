#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
struct edge{
	int to,next,v;
}e[N*6];
struct Edge{
	int x,y; ll v;
	bool operator <(const Edge &a)const{
		return v<a.v;
	}
}E[N*6];
int n,m,K,q,top;
int head[N],tot;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void build_edge(){
	static pll dis[N];
	static int vis[N];
	static priority_queue<pll> Q;
	For(i,1,n) dis[i]=pll(1ll<<60,0);
	For(i,1,K){
		dis[i]=pll(0,i);
		Q.push(pll(-dis[i].fi,i));
	}
	while (!Q.empty()){
		int x=Q.top().se; Q.pop();
		if (vis[x]) continue;
		vis[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to].fi>dis[x].fi+e[i].v){
				dis[e[i].to]=dis[x];
				dis[e[i].to].fi+=e[i].v;
				Q.push(pll(-dis[e[i].to].fi,e[i].to));
			}
	}
	For(i,1,n)
		for (int j=head[i];j;j=e[j].next)
			if (e[j].to>i&&dis[i].se!=dis[e[j].to].se)
				E[++top]=(Edge){dis[i].se,dis[e[j].to].se,dis[i].fi+dis[e[j].to].fi+e[j].v};
}
int nd,fa[N*2];
int f[N*2][20],dep[N*2];
ll val[N*2];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]); 
} 
void build_tree(){
	nd=K;
	For(i,1,nd) fa[i]=i;
	sort(E+1,E+top+1);
	For(i,1,top){
		//cout<<"EDG "<<E[i].x<<' '<<E[i].y<<' '<<E[i].v<<endl;
		int x=get(E[i].x);
		int y=get(E[i].y);
		if (x!=y){
			++nd; val[nd]=E[i].v;
			f[x][0]=f[y][0]=nd;
			fa[x]=fa[y]=fa[nd]=nd;
		}
	}
	For(i,1,17) For(j,1,nd)
		f[j][i]=f[f[j][i-1]][i-1];
	Rep(i,nd,1) dep[i]=dep[f[i][0]]+1;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,17,0) if (tmp&(1<<i)) x=f[x][i];
	Rep(i,17,0)
		if (f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return x==y?x:f[x][0];
}
int main(){
	scanf("%d%d%d%d",&n,&m,&K,&q);
	For(i,1,m){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	build_edge();
	build_tree();
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%lld\n",val[LCA(x,y)]);
	}
}