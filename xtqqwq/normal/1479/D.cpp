#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,tot,blo,mcnt,ncnt;
int v[600005],nxt[600005],h[300005],eu[600005],st[300005],ed[300005],a[300005],bl[300005],lf[1005],rg[1005];
int dep[300005],now[300005],sum[1005],f[300005][20],ans[300005];
bool vis[300005];

struct node{
	int l,r,x,y,opt,id;
	bool operator<(const node c)const{return l/blo==c.l/blo?(l/blo%2==0?r<c.r:r>c.r):l/blo<c.l/blo;}
}q[300005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void change(int x){
	now[a[x]]^=1;
	if(now[a[x]]==1) sum[bl[a[x]]]++;
	else sum[bl[a[x]]]--;
}

int find(int l,int r,int x){
	int lb=bl[l],rb=bl[r];
	if(lb==rb){
		for(int i=l;i<=r;i++) if(now[i]^(i==x)) return i;
		return -1;
	}
	for(int i=l;i<=rg[lb];i++) if(now[i]^(i==x)) return i;
	for(int i=lf[rb];i<=r;i++) if(now[i]^(i==x)) return i;
	for(int i=lb+1;i<=rb-1;i++){
		if(lf[i]<=x&&x<=rg[i]){
			for(int j=lf[i];j<=rg[i];j++) if(now[j]^(j==x)) return j;
		}
		else if(sum[i]){
			for(int j=lf[i];j<=rg[i];j++) if(now[j]^(j==x)) return j;
		}
	}
	return -1;
}

void dfs(int u,int fa){
	eu[++ncnt]=u,st[u]=ncnt;
	for(int i=1;i<=19;i++) f[u][i]=f[f[u][i-1]][i-1];
	for(int p=h[u];p;p=nxt[p]){
		if(v[p]==fa) continue;
		f[v[p]][0]=u,dep[v[p]]=dep[u]+1;
		dfs(v[p],u);
	}
	eu[++ncnt]=u,ed[u]=ncnt;
}

int lca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=19;i>=0;i--) if(dep[f[x][i]]>=dep[y]) x=f[x][i];
	if(x==y) return x;
	for(int i=19;i>=0;i--) if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}

void init(){
	blo=sqrt(n);
	for(int i=1;i<=n;i+=blo) lf[++mcnt]=i,rg[mcnt]=min(i+blo-1,n);
	for(int i=1;i<=mcnt;i++) for(int j=lf[i];j<=rg[i];j++) bl[j]=i;
}

int main(){
	n=readint(); m=readint();
	blo=sqrt(2*n);
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<n;i++) addedge(readint(),readint());
	dep[1]=1; dfs(1,-1);
	int x,y,z,w;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint(); w=readint();
		if(st[x]>st[y]) swap(x,y);
		int l=lca(x,y);
		q[i].x=z,q[i].y=w;
		if(l==x) q[i].l=st[x],q[i].r=st[y],q[i].id=i,q[i].opt=0;
		else q[i].l=ed[x],q[i].r=st[y],q[i].id=i,q[i].opt=l;
	}
	sort(q+1,q+m+1);
	init();
	int nl=1,nr=0;
	for(int i=1;i<=m;i++){
		while(nl>q[i].l) change(eu[--nl]);
		while(nr<q[i].r) change(eu[++nr]);
		while(nl<q[i].l) change(eu[nl++]);
		while(nr>q[i].r) change(eu[nr--]);
		ans[q[i].id]=find(q[i].x,q[i].y,a[q[i].opt]);
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}