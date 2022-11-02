#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,q,a[maxn];
struct node {
	int b[33],sz;
	void init() {
		sz=0;
		memset(b,0,sizeof(b));
	}
	void insert(int x) {
		for (int j=31;j>=0&&x;j--)
			if (x>>j&1) {
				if (!b[j]) { sz++; b[j]=x; break; }
				x^=b[j];
			}
	}
} tr[maxn*4],res;
int ori[maxn*4];
void merge(node &t1,node t2) {
	for (int i=0;i<=31;i++) t1.insert(t2.b[i]);
}
void pushup(int root) {
	tr[root]=tr[root<<1],merge(tr[root],tr[root<<1|1]);
}
void build(int l,int r,int root) {
	if (l==r) { tr[root].insert(ori[l]=(a[l]^a[l-1])); return; }
	int mid=(l+r)>>1; build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void add(int x,int l,int r,int root,int delta) {
	if (l==r) { tr[root].init(); tr[root].insert(ori[l]^delta); ori[l]^=delta; return; }
	int mid=(l+r)>>1; if (x<=mid) add(x,l,mid,root<<1,delta); else add(x,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) { merge(res,tr[root]); return; }
	int mid=(l+r)>>1; if (L<=mid) query(L,R,l,mid,root<<1);
	if (mid<R) query(L,R,mid+1,r,root<<1|1);
}
namespace BIT {
	int tr[maxn];
	void add(int x,int delta) {
		for (;x<=n;x+=x&(-x)) tr[x]^=delta;
	}
	int query(int x) {
		int res=0; for (;x;x-=x&(-x)) res^=tr[x];
		return res;
	}
};
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) {
		BIT::add(i,a[i]^a[i-1]);
	}
	build(1,n,1);
	int op,l,r,k;
	while (q--) {
		read(op),read(l),read(r);
		if (op==1) {
			read(k);
			BIT::add(l,k),BIT::add(r+1,k);
			add(l,1,n,1,k); if (r<n) add(r+1,1,n,1,k);
		} else {
			res.init();
			if (l<r) query(l+1,r,1,n,1);
			res.insert(BIT::query(l));
			printf("%d\n",(1<<res.sz));
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