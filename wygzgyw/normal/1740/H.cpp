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
const int maxn=(3e5)+10;
int n,fa[maxn],sz[maxn],tot,nxt[maxn],to[maxn],head[maxn];
void add(int x,int y) { tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; }
int top[maxn],son[maxn],dep[maxn];
void dfs1(int u) {
	sz[u]=1; for (int i=head[u],v;i;i=nxt[i]) { v=to[i],dep[v]=dep[u]+1; dfs1(v); sz[u]+=sz[v]; if (sz[v]>sz[son[u]]) son[u]=v; }
}
int bg[maxn],bk[maxn],ed[maxn];
int L[maxn],R[maxn],lgtson[maxn];
void dfs2(int u) {
	bg[u]=++tot,bk[tot]=u;
	if (son[u]) top[son[u]]=top[u],dfs2(son[u]);
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (v!=son[u]) top[v]=v,dfs2(v),lgtson[u]++;
	}
	ed[u]=tot;
}
struct node {
	int a,b,c; ll s1,s2;
	friend node operator + (node A,node B) {
		node res;
		res.a=A.a;
		if (A.b==B.a) res.b=B.b,res.s1=A.s1+B.s1;
		else res.b=B.c,res.s1=A.s1+B.s2;
		if (A.c==B.a) res.c=B.b,res.s2=A.s2+B.s1;
		else res.c=B.c,res.s2=A.s2+B.s2;
		return res;
	}
} leaf;
struct seg1 {
	vector<node> tr;
	int n;
	void init(int _n) {
		n=_n;
		tr.resize(n*4+2);
	}
	void change(int x,int l,int r,int root,node A) {
		if (l==r) { tr[root]=A; return; }
		int mid=(l+r)>>1;
		if (x<=mid) change(x,l,mid,root<<1,A);
		else change(x,mid+1,r,root<<1|1,A);
		tr[root]=tr[root<<1|1]+tr[root<<1];
	}
	void change(int x,node A) { change(x,1,n,1,A); }
	bool flag; node res;
	void query(int L,int R,int l,int r,int root) {
		if (L<=l&&r<=R) {
			if (!flag) res=tr[root],flag=1; else res=res+tr[root]; return;
		}
		int mid=(l+r)>>1;
		if (mid<R) query(L,R,mid+1,r,root<<1|1);
		if (L<=mid) query(L,R,l,mid,root<<1);
	}
	node query(int l,int r) {
		flag=0; query(l,r,1,n,1); return res;
	}
} T1[maxn];
int lst[maxn];
struct seg2 {
	vector<int> tr;
	int n;
	void init(int _n) {
		if (_n==0) { n=0; return; }
		n=_n+4;
		tr.resize(n*4+6);
	}
	void add(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]+=delta; return; }
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	void add(int x,int delta) {
		x=min(x,n);
		add(x,0,n,1,delta);
	}
	int query(int L,int R,int l,int r,int root) {
		if (tr[root]>0) return -1;
		if (L<=l&&r<=R) {
			if (l==r) return l;
			int mid=(l+r)>>1;
			if (tr[root<<1]==0) return query(L,R,l,mid,root<<1);
			return query(L,R,mid+1,r,root<<1|1);
		}
		int mid=(l+r)>>1,res=-1;
		if (L<=mid) { res=query(L,R,l,mid,root<<1); if (res!=-1) return res; }
		if (mid<R) res=query(L,R,mid+1,r,root<<1|1); return res;
	}
	pair<int,int> query() {
		int x=query(0,n,0,n,1);
		assert(x!=-1&&x+1<=n);
		int y=query(x+1,n,0,n,1);
		assert(y!=-1);
		return MP(x,y);
	}
} T2[maxn];
int lstval[maxn]; ll all[maxn],lstall[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); n++;
	for (int i=2;i<=n;i++) read(fa[i]),add(fa[i],i);
	tot=0;
	dep[1]=top[1]=1,dfs1(1),dfs2(1);
	leaf=(node){0,1,0,1,0};
	for (int i=1;i<=n;i++) L[i]=1e9,R[i]=0;
	for (int i=1;i<=n;i++) L[top[i]]=min(L[top[i]],bg[i]),R[top[i]]=max(R[top[i]],bg[i]);
	for (int i=1;i<=n;i++) if (top[i]==i) T1[i].init(R[i]-L[i]+1);
	for (int i=1;i<=n;i++) T2[i].init(lgtson[i]);
	for (int i=1;i<=n;i++) {
		int x=i;
		lst[top[i]]=bg[i];
		T1[top[i]].change(bg[i]-bg[top[i]]+1,leaf);
		if (fa[i]&&i!=son[fa[i]]) T2[fa[i]].add(0,1);
		//printf("i=%d\n",i);
		while (x) {
			int y=top[x];
			if (y!=1) {
				int z=fa[y];
				node res=T1[y].query(1,lst[y]-bg[y]+1);
				int vy=res.c;
				T2[z].add(lstval[y],-1);
				T2[z].add(vy,1);
				//printf("y=%d,z=%d,vy=%d\n",y,z,vy);
				ll ay=res.s2;
				all[z]+=ay-lstall[y];
				auto [X,Y]=T2[z].query();
				//printf("%d %d\n",X,Y);
				T1[top[z]].change(bg[z]-bg[top[z]]+1,(node){X,Y,X,all[z]+Y,all[z]+X});
				lstval[y]=vy;
				lstall[y]=ay;
			}
			x=fa[y];
		}
		node res=T1[1].query(1,lst[1]);
		if (i>1) printf("%lld\n",res.s2);
	}
	return 0;
}