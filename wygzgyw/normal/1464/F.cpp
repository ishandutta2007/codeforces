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
#define MP make_pair
typedef long long ll;
const int maxn=(2e5)+10;
int n,q,tot;
vector<int> g[maxn];
multiset<pair<int,int> > LCA; multiset<pair<int,int> >::iterator it;
int fa[maxn][20],bg[maxn],ed[maxn],bkdfn[maxn];
int dep[maxn],st[maxn*2][20],lg[maxn*2],bk[maxn];
int sz[maxn],top[maxn],son[maxn];
void dfs(int u,int p) {
	dep[u]=dep[p]+1; st[++tot][0]=u;
	bkdfn[u]=tot; fa[u][0]=p; sz[u]=1;
	for (int v : g[u]) if (v!=p) {
		dfs(v,u);
		st[++tot][0]=u;
		if (sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int p) {
	bg[u]=++tot; bk[tot]=u;
	if (son[u]) top[son[u]]=top[u],dfs2(son[u],u);
	for (int v : g[u]) if (v!=p&&v!=son[u]) top[v]=v,dfs2(v,u);
	ed[u]=tot;
}
int MN(int x,int y) { if (dep[x]<dep[y]) return x; return y; }
int lca(int x,int y) {
	x=bkdfn[x],y=bkdfn[y]; if (x>y) swap(x,y);
	int j=lg[y-x+1];
	return MN(st[x][j],st[y-(1<<j)+1][j]);
}
int dis(int x,int y) {
	return dep[x]+dep[y]-2*dep[lca(x,y)];
}
namespace BIT {
	int t1[maxn],t2[maxn];
	void add(int x,int delta,int *tr) {
		if (x<=0) return;
		for (;x<=n;x+=x&(-x)) tr[x]+=delta;
	}
	int query(int x,int *tr) {
		if (x<=0) return 0;
		int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res;
	}
	void add(int l,int r,int delta,int *tr) {
		if (l>r) return;
		add(l,delta,tr); add(r+1,-delta,tr);
	}
	int query(int l,int r,int *tr) { if (l>r) return 0; return query(r,tr)-query(l-1,tr); }
};
namespace xyr {
void ADD(int x,int y,int delta) {
	while (top[x]!=top[y]) {
		BIT::add(bg[top[x]],bg[x],delta,BIT::t1);
		x=fa[top[x]][0];
	}
	BIT::add(bg[y],bg[x],delta,BIT::t1);
}
void ADD(int x,int y,int z,int delta) {
	ADD(x,z,delta),ADD(y,z,delta),ADD(z,z,-delta);
}
int query(int x) {
	return BIT::query(bg[x],BIT::t1);
}
};
namespace Seg {
	struct node {
		int x,y,d;
		friend node operator + (node t1,node t2) {
			if (!t1.x) return t2; if (!t2.x) return t1;
			int A=dis(t1.x,t2.x),B=dis(t1.x,t2.y),C=dis(t1.y,t2.x),D=dis(t1.y,t2.y);
			int mx=max(max(A,B),max(C,D)); mx=max(max(mx,t1.d),t2.d);
			if (A==mx) return (node){t1.x,t2.x,mx};
			if (B==mx) return (node){t1.x,t2.y,mx};
			if (C==mx) return (node){t1.y,t2.x,mx};
			if (D==mx) return (node){t1.y,t2.y,mx};
			if (t1.d==mx) return t1; return t2;
		}
	} tr[maxn*4],res;
	int cnt[maxn*4];
	void add(int x,int l,int r,int root,int delta) {
		if (l==r) {
			cnt[root]+=delta;
			if (!cnt[root]) tr[root]=(node){0,0,0};
			else tr[root]=(node){bk[l],bk[l],0};
			return;
		}
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta); else add(x,mid+1,r,root<<1|1,delta);
		tr[root]=(tr[root<<1]+tr[root<<1|1]);
	}
	
	void query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) { res=res+tr[root]; return; }
		int mid=(l+r)>>1;
		if (L<=mid) query(L,R,l,mid,root<<1);
		if (mid<R) query(L,R,mid+1,r,root<<1|1);
	}
	
};
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(q); int op,z,x,y,d;
	for (int i=1;i<n;i++) {
		read(x),read(y);
		g[x].push_back(y),g[y].push_back(x);
	}
	dfs(1,0); tot=0; top[1]=1; dfs2(1,0);
	for (int i=2;i<=n*2;i++) lg[i]=lg[i>>1]+1;
	for (int i=1;i<=19;i++) for (int j=1;j+(1<<i)-1<=n*2;j++)
		st[j][i]=MN(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	for (int i=1;i<=19;i++) for (int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	int now=0;
	//for (int i=1;i<=n;i++) printf("%d %d\n",i,bg[i]);
	while (q--) {
		read(op); if (op<=2) read(x),read(y),z=lca(x,y);
		if (op==1) {
			now++;
			LCA.insert(MP(dep[z],z));
			xyr::ADD(x,y,z,1);
			BIT::add(bg[z],1,BIT::t2);
			Seg::add(bg[z],1,n,1,1);
		} else if (op==2) {
			now--;
			LCA.erase(LCA.find(MP(dep[z],z)));
			xyr::ADD(x,y,z,-1);
			BIT::add(bg[z],-1,BIT::t2);
			Seg::add(bg[z],1,n,1,-1);
		} else {
			read(d);
			it=LCA.end(); it--; x=(*it).second;
			y=x; for (int i=19;i>=0;i--) if (fa[y][i]&&dep[fa[y][i]]>=dep[x]-d) y=fa[y][i];
			x=y; for (int i=19;i>=0;i--) if (fa[y][i]&&dep[fa[y][i]]>=dep[x]-d) y=fa[y][i];
			//cerr<<x<<endl; cerr<<y<<endl;
			int cnt=xyr::query(y);
			cnt+=BIT::query(bg[y]+1,ed[y],BIT::t2);
			if (cnt!=now) { puts("No"); continue; }
			//printf("%d\n",cnt);
			Seg::res=(Seg::node){0,0,0};
			Seg::query(bg[y],ed[y],1,n,1);
			//printf("?? %d %d\n",Seg::res.x,Seg::res.y);
			int mx=max(dis(Seg::res.x,x),dis(Seg::res.y,x));
			if (mx<=d) puts("Yes");
			else puts("No");
		}
	}
	
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