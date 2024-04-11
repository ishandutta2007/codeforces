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
const int N=20005;
const int M=400005;
vector<pii> E[N];
int dep[N],fa[N][16],fav[N][16];
int n,m,S,T,nd,jud[N*2];
int head[M],vis[M],tot=1;
int dis[M],q[M];
struct edge{
	int to,next,f;
}e[M*5];
void add(int x,int y,int f){
	e[++tot]=(edge){y,head[x],f};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],0};
	head[y]=tot;
}
bool bfs(){
	For(i,1,nd) dis[i]=-1;
	int h=0,t=1;
	q[1]=S; dis[S]=0;
	while (h!=t){
		int x=q[++h];
		for (int i=head[x];i;i=e[i].next)
			if (dis[e[i].to]==-1&&e[i].f){
				dis[e[i].to]=dis[x]+1;
				if (e[i].to==T) return 1;
				q[++t]=e[i].to;
			}
	}
	return 0;
}
int dfs(int x,int flow){
	if (x==T) return flow;
	int k,rest=flow;
	for (int i=head[x];i&&rest;i=e[i].next)
		if (dis[e[i].to]==dis[x]+1&&e[i].f){
			k=dfs(e[i].to,min(rest,e[i].f));
			e[i].f-=k; e[i^1].f+=k; rest-=k;
		}
	if (rest) dis[x]=-1;
	return flow-rest;
}
void dfs(int x){
	for (auto i:E[x])
		if (i.fi!=fa[x][0]){
			dep[i.fi]=dep[x]+1;
			fa[i.fi][0]=x;
			fav[i.fi][0]=i.se;
			dfs(i.fi);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	Rep(i,14,0)
		if (tmp&(1<<i))
			x=fa[x][i];
	Rep(i,14,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main(){
	#ifdef zyy 
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&m);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		E[x].PB(pii(y,i));
		E[y].PB(pii(x,i));
	}
	S=nd=n; T=++nd;
	For(i,1,n-1) add(S,i,1),jud[i]=tot;
	For(i,1,m) add(++nd,T,1),jud[i+n]=tot;
	dfs(1);
	For(i,1,14) For(j,1,n){
		fa[j][i]=fa[fa[j][i-1]][i-1];
		if (dep[j]>=1<<i){
			fav[j][i]=++nd;
			add(fav[j][i-1],fav[j][i],1<<30);
			add(fav[fa[j][i-1]][i-1],fav[j][i],1<<30);
		}
	}
	For(i,1,m){
		int p=n+1+i,x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y);
		Rep(j,14,0){
			if (dep[x]-dep[L]>=1<<j)
				add(fav[x][j],n+1+i,1<<30),x=fa[x][j];
			if (dep[y]-dep[L]>=1<<j)
				add(fav[y][j],n+1+i,1<<30),y=fa[y][j];
		}
		assert(x==L&&y==L);
	}
	int tmp=0;
	for (;bfs();tmp+=dfs(S,1<<30));
	vector<int> ans1,ans2;
	For(i,1,n-1) if (dis[i]==-1) ans1.PB(i);
	For(i,1,m) if (dis[i+n+1]!=-1) ans2.PB(i);
	assert(ans1.size()+ans2.size()==tmp);
	printf("%d\n",ans1.size()+ans2.size());
	printf("%d ",ans2.size());
	for (auto i:ans2) printf("%d ",i); puts("");
	printf("%d ",ans1.size());
	for (auto i:ans1) printf("%d ",i); puts("");
}