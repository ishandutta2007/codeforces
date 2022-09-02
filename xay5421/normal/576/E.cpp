#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define mp std::make_pair
#define fi first
#define se second
#define lc u<<1
#define rc u<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
#define debug(...) fprintf(stderr,__VA_ARGS__)
typedef std::pair<int,int> pii;
const int N=500005,K=55;
int n,m,k,q,top,uu[N],vv[N],pre[N],col[N],right[N];std::vector<pii>g[N<<2];pii cg[N],p[N<<1];
struct dsu{
	int col,w[N],fa[N],dep[N];
	int find(int x){return fa[x]?find(fa[x]):x;}
	int dist(int x){return fa[x]?dist(fa[x])^w[x]:0;}
	void merge(int a,int b){
		int faa=find(a),fab=find(b);if(faa==fab)return;
		if(dep[faa]<dep[fab])std::swap(a,b),std::swap(faa,fab);
		if(dep[faa]==dep[fab])++dep[faa],p[++top]=mp(col,-faa);
		w[fab]=dist(a)^dist(b)^1;
		fa[fab]=faa,p[++top]=mp(col,fab);
	}
}d[K];
void mdf(int u,int l,int r,int lx,int rx,int a,int b){
	if(l==lx&&r==rx)return g[u].pb(mp(a,b)),void();int mid=(l+r)>>1;
	if(rx<=mid)mdf(ls,lx,rx,a,b);else if(mid<lx)mdf(rs,lx,rx,a,b);else mdf(ls,lx,mid,a,b),mdf(rs,mid+1,rx,a,b);
}
void reset(int temp){
	while(top>temp){
		int x=p[top].fi;
		if(p[top].se>0){
			int u=p[top].se;
			d[x].fa[u]=0;
			d[x].w[u]=0;
		}else{
			int u=-p[top].se;--d[x].dep[u];
		}
		--top;
	}
}
void dfs(int u,int l,int r){
	int temp=top;
	for(int i=0;i<g[u].size();++i){
		int a=uu[g[u][i].fi],b=vv[g[u][i].fi],c=g[u][i].se;
		d[c].merge(a,b);
	}
	if(l==r){
		int a=uu[cg[l].fi],b=vv[cg[l].fi],c=cg[l].se;
		if(d[c].find(a)!=d[c].find(b)||d[c].dist(a)!=d[c].dist(b)){
			puts("YES"),col[cg[l].fi]=c;
		}else puts("NO");
		if(l<q){
			int ri=right[l]?right[l]:q;
			if(l+1<=ri)mdf(1,1,q,l+1,ri,cg[l].fi,col[cg[l].fi]);
		}
		return;
	}
	int mid=(l+r)>>1;dfs(ls),dfs(rs);
	reset(temp);
}
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;++i)d[i].col=i;
	for(int i=1;i<=m;++i)scanf("%d%d",&uu[i],&vv[i]);
	for(int i=1;i<=q;++i){
		int a,b;scanf("%d%d",&a,&b);
		cg[i]=mp(a,b);
		if(pre[a])right[pre[a]]=i-1;pre[a]=i;
	}
	dfs(1,1,q);
	return 0;
}