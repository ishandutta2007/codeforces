#include<set>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
const int N=200005,M=300005,K=20;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
int max(int a,int b){return a>b?a:b;}
int n,m,s,ans,id[N],sz[N],fa[N][K],dis[N],dep[N];std::vector<int>g[N];
struct cmp{
	bool operator()(const int&x,const int&y){return dis[x]^dis[y]?dis[x]<dis[y]:x<y;} 
};
std::set<int,cmp>S;
struct ed{ed*nxt;int to,w;}pool[M<<1],*p=pool,*lnk[N];
void ae(int u,int v,int w){*++p=(ed){lnk[u],v,w},lnk[u]=p;}
bool cmp(int a,int b){return dis[a]<dis[b];}
int lca(int u,int v){
	if(dep[u]<dep[v])u^=v^=u^=v;int ret=dep[u]-dep[v];
	for(int i=K-1;~i;--i)if(ret>>i&1)u=fa[u][i];if(u==v)return u;
	for(int i=K-1;~i;--i)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];return fa[u][0];
}
void dfs(int u){
	sz[u]=1;
	for(int i=0;i<(int)g[u].size();++i){
		int v=g[u][i];
		dfs(v);
		sz[u]+=sz[v];
	}
	if(u!=s)ans=max(ans,sz[u]);
}
signed main(){
	memset(dis,63,sizeof(dis));
	rd(n),rd(m),rd(s);
	rep(i,1,n)id[i]=i;
	rep(i,1,m){
		int u,v,w;rd(u),rd(v),rd(w);
		ae(u,v,w),ae(v,u,w);
	}
	dis[s]=0,S.insert(s);
	while(!S.empty()){
		int u=*S.begin();S.erase(S.begin());
		for(ed*i=lnk[u];i;i=i->nxt)
			if(dis[u]+i->w<dis[i->to]){
				S.erase(i->to);
				dis[i->to]=dis[u]+i->w;
				S.insert(i->to);
			}
	}
	std::sort(id+1,id+1+n,cmp);
	rep(_,1,n){
		int u=id[_];if(dis[u]>1e17)break;
		for(int i=1;i<K;++i)fa[u][i]=fa[fa[u][i-1]][i-1];
		dep[u]=dep[fa[u][0]]+1;
		for(ed*i=lnk[u];i;i=i->nxt)
			if(dis[u]+i->w==dis[i->to]){
				if(!fa[i->to][0])fa[i->to][0]=u;
				else fa[i->to][0]=lca(fa[i->to][0],u);
			}
	}
	rep(i,1,n)if(fa[i][0])g[fa[i][0]].push_back(i);
	dfs(s);
	printf("%I64d\n",ans);
	return 0;
}