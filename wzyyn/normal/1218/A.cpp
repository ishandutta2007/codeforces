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
const int N=15005;
struct edge{
	int to,next;
}e[N*2];
int fa[N],dep[N],q[N*2],vis[N];
int n,m,tot,head[N],sz[N],S[N*2];
int f[N],g[N],F[N*2],ans;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x])
			if (!dep[e[i].to]){
				fa[e[i].to]=x;
				dfs(e[i].to);
			}
			else if (dep[e[i].to]<dep[x]){
				q[++*q]=x;
				for (int y=x;y!=e[i].to;y=fa[y])
					q[++*q]=fa[y];
			}
}
void dfs2(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			dfs2(e[i].to,x);
			sz[x]+=sz[e[i].to];
			f[x]+=f[e[i].to];
		}
	g[x]=n+f[x];
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			g[x]=max(g[x],f[x]+(n-sz[e[i].to])-f[e[i].to]+g[e[i].to]);
	f[x]+=sz[x];
	//cout<<x<<' '<<fa<<' '<<f[x]<<' '<<g[x]<<endl;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		add(++x,++y); add(y,x);
	}
	dfs(1); m=*q;
	//For(i,1,*q) cout<<q[i]<<endl;
	For(i,1,m) vis[q[i]]=1;
	For(i,1,m) dfs2(q[i],0);
	For(i,1,m) q[i+m]=q[i];
	For(i,1,2*m) S[i]=S[i-1]+sz[q[i]];
	For(i,1,2*m) F[i]=f[q[i]];
	For(l,1,m-2){
		For(i,1,2*m-l+1) F[i]+=S[i+l-1]-S[i-1];
		For(i,1,2*m-l) F[i]=max(F[i]+f[q[i+l]],F[i+1]+f[q[i]]);
	}
	For(i,1,m) ans=max(ans,F[i+1]+g[q[i]]);
	printf("%d\n",ans);
}