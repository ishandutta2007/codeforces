#include<cstdio>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=500005;typedef long long ll;
int n,S,a[N],sz[N];ll ans[N];
struct ed{ed*nxt;int to;}pool[N<<1],*p=pool,*lnk[N];
void ae(int u,int v){*++p=(ed){lnk[u],v},lnk[u]=p;}
void pre(int u,int fa){
	sz[u]=1;
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa)pre(i->to,u),sz[u]+=sz[i->to];
}
void dfs(int u,int fa){
	if(ans[u]>ans[S])S=u;
	for(ed*i=lnk[u];i;i=i->nxt)if(i->to!=fa){
		ans[i->to]=ans[u]+1ll*(sz[u]-sz[i->to])*sz[i->to]; 
		dfs(i->to,u);
	}
}
void solve(int s){
	pre(s,0);
	ans[s]=1ll*n*(n-1)/2,S=s;
	dfs(s,0);
}
int main(){
	scanf("%d",&n);
	rep(i,2,n){
		int u,v;scanf("%d%d",&u,&v),ae(u,v),ae(v,u);
	}
	solve(1);
	solve(S);
	printf("%lld\n",ans[S]);
	return 0;
}