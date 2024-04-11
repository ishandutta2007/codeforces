#include<cstdio>
#include<algorithm>
#define ll long long
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define N 200005

char buf[1<<24],*p1=buf,*p2=buf,obuf[1<<24],*O=obuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

int n;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int fa[N],son[N],dep[N],sz[N];
inline void dfs1(int u){
	sz[u]=1;
	dep[u]=dep[fa[u]]+1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])
			continue;
		fa[v]=u;
		dfs1(v);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]])
			son[u]=v;
	}
}
int top[N],dfn[N],_dfn,ver[N];
inline void dfs2(int u){
	top[u]=u==son[fa[u]]?top[fa[u]]:u;
	dfn[u]=++_dfn;
	ver[_dfn]=u;
	if(son[u])
		dfs2(son[u]);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u]||v==son[u])
			continue;
		dfs2(v);
	}
}

inline int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])
			std::swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v;
}
inline int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
inline int up(int u,int d){
	while(1){
		if(dep[u]-dep[top[u]]+1<=d){
			d-=dep[u]-dep[top[u]]+1;
			u=fa[top[u]];
		}
		else
			return ver[dfn[u]-d];
	}
}
inline int jmp(int u,int v,int d){
	int w=lca(u,v);
	if(d<=dep[u]-dep[w])
		return up(u,d);
	else
		return up(v,dep[u]+dep[v]-2*dep[w]-d);
}

pii operator + (pii x,int u){
	int d=dis(x.fir,u);
	if(d<=x.sec)
		return x;
	return mp(jmp(x.fir,u,(d-x.sec)/2),(d+x.sec)/2);
}
bool operator < (pii x,pii y){
	return dis(x.fir,y.fir)+x.sec<=y.sec;
}

ll t1[N],t2[N];
inline int lb(int x){
	return x&-x;
}
inline void add_(int x,int d){
	for(int i=x;i<=2*n-1;i+=lb(i)){
		t1[i]+=d;
		t2[i]+=1ll*d*(x-1);
	}
}
inline void add(int l,int r,int d){
	add_(l,d),add_(r+1,-d);
}
inline ll sum_(int x){
	ll res=0;
	for(int i=x;i;i-=lb(i))
		res+=t1[i]*x-t2[i];
	return res;
}
inline ll sum(int l,int r){
	return sum_(r)-sum_(l-1);
}

inline void tr_add(int u,int d){
	while(u){
		add(dfn[top[u]],dfn[u],d);
		u=fa[top[u]];
	}
}
inline ll tr_sum(int u){
	ll res=0;
	while(u){
		res+=sum(dfn[top[u]],dfn[u]);
		u=fa[top[u]];
	}
	return res;
}

ll ans;
pii c[N];
std::vector<pii> qry[N];
inline void sol(int L,int R){
	if(L==R)
		return;
	int mid=(L+R)>>1;
	sol(L,mid),sol(mid+1,R);
	c[mid]=mp(mid,0);
	for(int i=mid-1;i>=L;i--)
		c[i]=c[i+1]+i;
	c[mid+1]=mp(mid+1,0);
	for(int i=mid+2;i<=R;i++)
		c[i]=c[i-1]+i;
	ll tmp=0;
	for(int i=L;i<=mid;i++)
		qry[i].clear();
	for(int i=mid+1,l=L-1,r=mid+1;i<=R;i++){
		while(r>L&&c[r-1]<c[i])
			--r;
		while(l<mid&&c[i]<c[l+1])
			tmp+=c[++l].sec;
		while(l>=L&&!(c[i]<c[l]))
			tmp-=c[l--].sec;
		ans+=1ll*(mid-r+1)*c[i].sec+tmp;
		qry[l].push_back(mp(i,-1));
		qry[r-1].push_back(mp(i,1));
	}
	tmp=0;
	for(int i=L;i<=mid;i++){
		tmp+=dep[c[i].fir]+c[i].sec;
		tr_add(c[i].fir,1);
		for(auto x:qry[i])
			ans+=x.sec*(1ll*(i-L+1)*(dep[c[x.fir].fir]+c[x.fir].sec)+tmp-2*tr_sum(c[x.fir].fir))/2;
	}
	for(int i=L;i<=mid;i++)
		tr_add(c[i].fir,-1);
}

int main(){
//	freopen(".in","r",stdin);
	rd(n);
	for(int i=1;i<n;i++){
		int u,v;
		rd(u),rd(v);
		addedge(u,n+i);
		addedge(n+i,u);
		addedge(v,n+i);
		addedge(n+i,v);
	}
	dfs1(1);
	dfs2(1);
	sol(1,n);
	printf("%lld\n",ans);
}