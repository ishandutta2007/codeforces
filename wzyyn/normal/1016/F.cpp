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
int n,Q,q[N];
int fa[N],vis[N];
int head[N],tot;
struct edge{
	int to,next,v;
}e[N*2];
ll dis[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot; 
} 
void dfs1(int x){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dis[e[i].to]=dis[x]+e[i].v;
			dfs1(e[i].to);
		}
}
void dfs2(int x,int fa,ll &v1,ll &v2,ll d){
	++v1; v2=max(v2,d);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa) dfs2(e[i].to,x,v1,v2,d+e[i].v);
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	dfs1(1);
	for (int i=n;i!=1;i=fa[i]) q[++*q]=i;
	q[++*q]=1;
	reverse(q+1,q+*q+1);
	For(i,1,*q) vis[q[i]]=1;
	ll mxd=-(1ll<<60),las=mxd,len=dis[n];
	For(i,1,*q){
		//cout<<q[i]<<' '<<dis[q[i]]<<endl;
		ll v1=0,v2=-(1ll<<60);
		for (int j=head[q[i]];j;j=e[j].next)
			if (!vis[e[j].to]) dfs2(e[j].to,q[i],v1,v2,e[j].v);
		//cout<<q[i]<<' '<<dis[q[i]]<<' '<<v1<<' '<<v2<<' '<<las<<endl;
		if (v1>=2) mxd=max(mxd,len);
		mxd=max(mxd,(len-dis[q[i]])+max(0ll,v2)+las);
		if (i!=1) mxd=max(mxd,dis[q[i-1]]+v2+(len-dis[q[i]]));
		if (i!=1) las=max(las,dis[q[i-1]]);
		las=max(las,dis[q[i]]+v2);
	}
	while (Q--){
		int x;
		scanf("%d",&x);
		printf("%lld\n",min(mxd+x,dis[n]));
	}
}