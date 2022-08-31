// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y,z;
	bool operator<(const node c)const{return z<c.z;}
}e[300005];

int n,q,ncnt;
int dfn[600005],rnk[600005],f[600005][20],dep[600005],mn[1100000],mx[1100000],mina[1100000],maxa[1100000],tag[1100000],fa[600005],val[600005];
vector<int> adj[600006];

int getf(int x){return x==fa[x]?x:fa[x]=getf(fa[x]);}

void dfs(int u){
	dfn[u]=++ncnt,rnk[ncnt]=u;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(auto v:adj[u]){
		f[v][0]=u,dep[v]=dep[u]+1;
		dfs(v);
	}
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void build(int id,int l,int r){
	mina[id]=n+n,maxa[id]=0,tag[id]=-1;
	if(l==r) return (void)(mn[id]=mx[id]=dfn[l]);
	int mid=(l+r)/2;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	mn[id]=min(mn[id<<1],mn[id<<1|1]);
	mx[id]=max(mx[id<<1],mx[id<<1|1]);
}

void addtag(int id,int c){
	tag[id]=c;
	if(!c) mina[id]=n+n,maxa[id]=0;
	else mina[id]=mn[id],maxa[id]=mx[id];
}

void pushdown(int id){
	if(tag[id]!=-1){
		addtag(id<<1,tag[id]);
		addtag(id<<1|1,tag[id]);
		tag[id]=-1;
	}
}

void cover(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(addtag(id,c));
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) cover(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) cover(id<<1|1,mid+1,r,ql,qr,c);
	else cover(id<<1,l,mid,ql,mid,c),cover(id<<1|1,mid+1,r,mid+1,qr,c);
	mina[id]=min(mina[id<<1],mina[id<<1|1]);
	maxa[id]=max(maxa[id<<1],maxa[id<<1|1]);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<n;i++) e[i].x=readint(),e[i].y=readint(),e[i].z=readint();
	sort(e+1,e+n);
	for(int i=1;i<=n;i++) fa[i]=i;
	int cnt=n;
	for(int i=1;i<n;i++){
		int fx=getf(e[i].x),fy=getf(e[i].y);
		cnt++;
		fa[fx]=fa[fy]=fa[cnt]=cnt;
		val[cnt]=e[i].z;
		adj[cnt].pb(fx),adj[cnt].pb(fy);
	}
	dep[cnt]=1; dfs(cnt);
	build(1,1,n);
	int x,y,opt;
	while(q--){
		opt=readint();
		if(opt==1){
			x=readint(); y=readint();
			cover(1,1,n,x,y,1);
		}
		else if(opt==2){
			x=readint(); y=readint();
			cover(1,1,n,x,y,0);
		}
		else{
			x=readint();
			if(!maxa[1]) printf("-1\n");
			else if(mina[1]==maxa[1]&&mina[1]==dfn[x]) printf("-1\n");
			else{
				int l=lca(rnk[mina[1]],rnk[maxa[1]]);
				printf("%d\n",val[lca(l,x)]);
			}
		}
	}
	return 0;
}