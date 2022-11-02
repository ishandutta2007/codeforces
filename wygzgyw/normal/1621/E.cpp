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
const int maxn=(1e5)+10;
int T,n,m,b[maxn];
ll sum[maxn]; int k[maxn];
vector<int> g[maxn];
int UP(ll x,int y) {
	if (x%y==0) return x/y; return x/y+1;
}
namespace Seg {
	int tr[maxn*4],lazy[maxn*4];
	void puttag(int root,int delta) {
		tr[root]+=delta,lazy[root]+=delta;
	}
	void pushdown(int root) {
		if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
	}
	void init(int l,int r,int root) {
		lazy[root]=0;
		if (l==r) { tr[root]=n-l+1; return; }
		int mid=(l+r)>>1;
		init(l,mid,root<<1),init(mid+1,r,root<<1|1);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	void add(int L,int R,int l,int r,int root,int delta) {
		if (L<=l&&r<=R) { puttag(root,delta); return; }
		int mid=(l+r)>>1; pushdown(root);
		if (L<=mid) add(L,R,l,mid,root<<1,delta);
		if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
};
void insert(int x,int delta) {
	x=lower_bound(b+1,b+n+1,x)-b;
//	printf("insert %d %d\n",x,delta);
	Seg::add(1,x,1,n+1,1,-delta);
}
int main() {
	read(T); while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(b[i]); sort(b+1,b+n+1);
		Seg::init(1,n+1,1);
		for (int i=1;i<=m;i++) {
			read(k[i]); int x; g[i].clear(); sum[i]=0;
			for (int j=1;j<=k[i];j++) read(x),g[i].push_back(x),sum[i]+=x;
			insert(UP(sum[i],k[i]),1);
		}
		for (int i=1;i<=m;i++) {
			insert(UP(sum[i],k[i]),-1);
			for (int &x : g[i]) {
				insert(UP(sum[i]-x,k[i]-1),1);
				if (Seg::tr[1]>=0) printf("1"); else printf("0");
				insert(UP(sum[i]-x,k[i]-1),-1);
			}
			insert(UP(sum[i],k[i]),1);
		}
		puts("");
		
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