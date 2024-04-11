#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=150010;
const ll mod=998244353;
int n,q,deg[maxn],fa[maxn][20],block;
ll tr[maxn],iv,tmp,ans,sum[maxn];
int sz[maxn],d[maxn],dep[maxn];
ll ksm(ll x,ll y) {
	ll res=1;
	while (y) {
		if (y&1) res=res*x%mod;
		x=x*x%mod; y>>=1;
	} return res;
}
void update(ll &x,ll y) {
	x+=y; if (x>=mod) x-=mod;
}
int tot,nxt[maxn*2],to[maxn*2],head[maxn];
int bg[maxn],ed[maxn];
void add_edge(int x,int y) {
	tot++; nxt[tot]=head[x];
	head[x]=tot; to[tot]=y;
}
void dfs(int u,int p) {
	bg[u]=++tot;
	fa[u][0]=p;
	sz[u]=1;
	dep[u]=dep[p]+1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=p) dfs(v,u),sz[u]+=sz[v];
	}
	ed[u]=tot;
}
void add(int l,int r,ll delta) {
	for (int x=l;x<=n;x+=x&(-x)) update(tr[x],delta);
	for (int x=r+1;x<=n;x+=x&(-x)) update(tr[x],mod-delta);
}
ll query(int x) {
	ll res=0;
	for (;x>0;x-=x&(-x)) update(res,tr[x]);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q);
	int op,x,y,z,len;
	iv=ksm(n,mod-2);
	for (int i=1;i<n;i++) {
		read(x); read(y);
		add_edge(x,y); add_edge(y,x);
		deg[x]++; deg[y]++;
	}
	block=floor(sqrt(n*1.0))+1;
	tot=0;
	dfs(1,0);
//	for (int i=1;i<=n;i++) printf("%d %d\n",bg[i],ed[i]);
	tot=0;
	for (int i=1;i<=n;i++)
		if (deg[i]>block) d[++tot]=i;
	for (int j=1;j<=18;j++)
	for (int i=1;i<=n;i++)
		fa[i][j]=fa[fa[i][j-1]][j-1];
	while (q--) {
		read(op); read(x);
		if (op==2) {
			ans=query(bg[x]);
			for (register int i=1;i<=tot;++i) {
				y=d[i];
				if (x==y) update(ans,sum[y]*n%mod);
				else {
					if (bg[y]<=bg[x]&&bg[x]<=ed[y]) {
						z=x;
						for (int j=18;j>=0;j--)
							if (dep[fa[z][j]]>dep[y]) z=fa[z][j];
						update(ans,sum[y]*(n-sz[z])%mod);
					} else update(ans,sum[y]*sz[y]%mod);
				}
			}
			printf("%lld\n",ans*iv%mod);
		} else {
			read(y);
			if (deg[x]<=block) {
				for (register int i=head[x],v;i;i=nxt[i]) {
					v=to[i];
					if (v==fa[x][0]) {
						tmp=(ll)(sz[x]-1+mod)*y%mod;
						add(1,bg[x]-1,tmp);
						add(ed[x]+1,n,tmp);
					} else {
						tmp=(ll)(n-sz[v]-1)*y%mod;
						add(bg[v],ed[v],tmp);
					}
				}
				add(bg[x],bg[x],(ll)(n-1)*y%mod);
				add(1,n,y);
			} else update(sum[x],y);
		}
	}
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/