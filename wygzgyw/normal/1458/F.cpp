// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
typedef long long ll;
const int maxn=(2e5)+10;
int n,st[maxn*2][22],lg[maxn*2],euler[maxn*2],tot,sz[maxn],fa[maxn],top[maxn];
int son[maxn],dep[maxn],bk[maxn];
vector<int> g[maxn];
int dfn[maxn],bkdfn[maxn];
void dfs1(int u,int p) {
	euler[++tot]=u; bk[u]=tot;
	sz[u]=1; fa[u]=p; dep[u]=dep[p]+1;
	for (int v : g[u]) if (v!=p) {
		dfs1(v,u); sz[u]+=sz[v]; euler[++tot]=u;
		if (!son[u]||sz[v]>sz[son[u]]) son[u]=v;
	}
}
int MN(int x,int y) {
	if (dep[x]<dep[y]) return x;
	return y;
}
int lca(int x,int y) {
	x=bk[x],y=bk[y]; if (x>y) swap(x,y);
	int j=lg[y-x+1]; return MN(st[x][j],st[y-(1<<j)+1][j]);
}
void dfs2(int u) {
	dfn[u]=++tot; bkdfn[tot]=u;
	if (son[u]) top[son[u]]=top[u],dfs2(son[u]);
	for (int v : g[u]) if (v!=fa[u]&&v!=son[u]) {
		top[v]=v; dfs2(v);
	}
}
int dis(int x,int y) { return dep[x]+dep[y]-2*dep[lca(x,y)]; }
ll ans,s1,s2;
struct node {
	int x,y,d;
	friend node operator + (node A,node B) {
		node res; if (A.d>B.d) res=A; else res=B;
		int t1=dis(A.x,B.x),t2=dis(A.x,B.y),t3=dis(A.y,B.x),t4=dis(A.y,B.y);
		if (t1>res.d) res=(node){A.x,B.x,t1};
		if (t2>res.d) res=(node){A.x,B.y,t2};
		if (t3>res.d) res=(node){A.y,B.x,t3};
		if (t4>res.d) res=(node){A.y,B.y,t4};
		return res;
	}
} pre[maxn];
int rem[maxn];
ll sum[maxn];
int Get(node A) {
	int x=A.x,y=A.y,d=A.d;
	if (x==y) return x;
	if (dep[x]==dep[y]) return lca(x,y);
	if (dep[x]<dep[y]) swap(x,y);
	int z=x;
	//printf("in %d %d %d\n",x,y,d);
	while (fa[top[z]]&&dep[x]-dep[fa[top[z]]]<=d/2) {
		//if(z) printf("%d %d\n",z,fa[top[z]]);
		z=fa[top[z]];
	}
	int l=dfn[top[z]],r=dfn[z],res;
	//printf("out %d %d\n",x,y);
	while (l<=r) {
		int mid=(l+r)>>1;
		if (dep[x]-dep[bkdfn[mid]]<=d/2) res=mid,r=mid-1;
		else l=mid+1;
	}
	return bkdfn[res];
}
namespace BIT {
	ll t1[maxn],t2[maxn];
	void add1(int x,ll delta) { for (;x<=n*2;x+=x&(-x)) t1[x]+=delta; }
	void add2(int x,ll delta) { for (;x<=n*2;x+=x&(-x)) t2[x]+=delta; }
	void add(int l,int r,ll delta) {
		//printf("%d %d %lld\n",l,r,delta);
		add1(l,delta),add1(r+1,-delta);
		add2(l,delta*l),add2(r+1,-delta*(r+1));
	}
	ll query1(int x) { ll res=0; for (;x;x-=x&(-x)) res+=t1[x]; return res; }
	ll query2(int x) { ll res=0; for (;x;x-=x&(-x)) res+=t2[x]; return res; }
	ll query(int x) {
		return query1(x)*(x+1)-query2(x);
	}
	ll query(int l,int r) {
		return query(r)-query(l-1);
	}
};
void del(int x) {
	//printf("del %d\n",x);
	s1--; s2-=dep[x];
	while (x) BIT::add(dfn[top[x]],dfn[x],-2),x=fa[top[x]];
}
void insert(int x) {
	//printf("add %d\n",x);
	s1++; s2+=dep[x];
	while (x) BIT::add(dfn[top[x]],dfn[x],2),x=fa[top[x]];
}
ll query(int x) {
	ll res=dep[x]*s1+s2;
	while (x) res-=BIT::query(dfn[top[x]],dfn[x]),x=fa[top[x]];
	return res;
}
void solve(int l,int r) {
	if (l==r) return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	assert(s1==0&&s2==0);
	//printf("%d %d\n",l,r);
	pre[mid+1]=(node){mid+1,mid+1,0}; sum[mid]=sum[mid+1]=0;
	for (int i=mid+2;i<=r;i++) pre[i]=(pre[i-1]+(node){i,i,0}),sum[i]=sum[i-1]+pre[i].d;
	pre[mid]=(node){mid,mid,0};
	for (int i=mid-1;i>=l;i--) pre[i]=(pre[i+1]+(node){i,i,0});
	
	for (int i=mid;i>=l;i--) rem[i]=Get(pre[i]);
	for (int i=mid+1;i<=r;i++) rem[i]=Get(pre[i]);
	
	int p1=mid+1,p2=mid;
	for (int i=mid;i>=l;i--) {
		while (p2<r) {
			if (2*(pre[i]+pre[p2+1]).d==pre[i].d+pre[p2+1].d+2*dis(rem[i],rem[p2+1])) {
				p2++; insert(rem[p2]);
			}
			else break;
		}
		while (p1<=r&&(pre[i]+pre[p1]).d==pre[i].d) del(rem[p1]),p1++;
		//printf("[%d,%d] %d %d %d %lld\n",l,r,i,p1,p2,query(rem[i]));
		ans+=(ll)(p1-mid-1)*pre[i].d;
		ans+=(ll)(p2-p1+1)*(pre[i].d/2)+(sum[p2]-sum[p1-1])/2+query(rem[i]);
		ans+=sum[r]-sum[p2];
	}
	while (p1<=p2) del(rem[p1]),p1++;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); int x,y;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(i+n),g[y].push_back(i+n);
		g[i+n].push_back(x); g[i+n].push_back(y);
	}
	dfs1(1,0);
	top[1]=1; tot=0; dfs2(1);
	for (int i=2;i<=n*4;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=n*4;i++) st[i][0]=euler[i];
	for (int i=1;i<=20;i++) for (int j=1;j+(1<<i)-1<=n*4;j++)
		st[j][i]=MN(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	solve(1,n);
	printf("%lld\n",ans>>1);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/