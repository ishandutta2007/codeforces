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
int q,n,d;
bool mk[maxn];
namespace BIT {
	int tr[maxn];
	void add(int x,int y) { for (;x<=n;x+=x&(-x)) tr[x]+=y; }
	int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
	int query(int l,int r) { if (l>r) return 0; return query(r)-query(l-1); }
};
ll s2[maxn*4],s1[maxn*4],s0[maxn*4],lazy[maxn*4];
void puttag(int root,ll delta) {
	lazy[root]+=delta;
	s2[root]+=delta*delta*s0[root]+2*delta*s1[root];
	s1[root]+=delta*s0[root];
}
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void pushup(int root) {
	s0[root]=s0[root<<1]+s0[root<<1|1];
	s1[root]=s1[root<<1]+s1[root<<1|1];
	s2[root]=s2[root<<1]+s2[root<<1|1];
}
void add(int x,int l,int r,int root,int A) {
	if (l==r) {
		s0[root]=1;
		s1[root]=A;
		s2[root]=(ll)A*A;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(root);
	if (x<=mid) add(x,l,mid,root<<1,A);
	else add(x,mid+1,r,root<<1|1,A);
	pushup(root);
}
void del(int x,int l,int r,int root) {
	if (l==r) {
		s0[root]=0;
		s1[root]=0;
		s2[root]=0;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(root);
	if (x<=mid) del(x,l,mid,root<<1);
	else del(x,mid+1,r,root<<1|1);
	pushup(root);
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	pushdown(root); int mid=(l+r)>>1;
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int main() {
	read(q);
	n=2e5;
	read(d);
	while (q--) {
		int x,delta; read(x);
		if (mk[x]) delta=-1; else delta=1;
		mk[x]^=1;
		BIT::add(x,delta);
		if (delta==1) {
			add(x,1,n,1,BIT::query(max(1,x-d),x-1));
			add(x+1,min(n,x+d),1,n,1,1);
		} else {
			del(x,1,n,1);
			add(x+1,min(n,x+d),1,n,1,-1);
		}
		printf("%lld\n",(s2[1]-s1[1])/2);
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