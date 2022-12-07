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
const int N=300005;
struct edge{
	int to,next,v;
}e[N*2];
int n,Q,v[N];
int head[N],tot;
int fa[N][20],dep[N];
ll f[N],F[N],g[N],G[N];
ll S1[N],S2[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot; 
}
void dfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			fa[e[i].to][0]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
}
void init1(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			init1(e[i].to);
			F[e[i].to]=max(0ll,f[e[i].to]+v[e[i].to]-2*e[i].v);
			f[x]+=F[e[i].to];
		}
}
void init2(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			g[e[i].to]=f[x]+G[x]-F[e[i].to];
			G[e[i].to]=max(0ll,g[e[i].to]+v[x]-2*e[i].v);
			init2(e[i].to);
		}
}
void init3(int x){
	S1[x]+=f[x]+G[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x][0]){
			S1[e[i].to]=S1[x];
			S2[e[i].to]=S2[x]-F[e[i].to]-G[e[i].to]-e[i].v+v[e[i].to];
			init3(e[i].to);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,18) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,18,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs(1);
	init1(1);
	init2(1);
	init3(1);
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	//For(i,2,n)
	//	printf("INFO %lld %lld\n",F[i],G[i]);
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		int L=LCA(x,y);
		ll ans=S1[x]+S1[y]-S1[L]-S1[fa[L][0]];
		//cout<<ans<<endl;
		ans+=S2[x]+S2[y]-2*S2[L];
		//cout<<ans<<endl;
		ans+=v[L];
		printf("%lld\n",ans);
	}
}