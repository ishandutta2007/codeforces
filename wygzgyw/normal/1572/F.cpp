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
const int INF=1e9;
const int maxn=(2e5)+10;
int n,q,lazy[maxn*4];
struct node {
	int mx,mx2,cnt;
	void init(int x) { mx=x,mx2=0,cnt=1; }
	friend node operator + (node A,node B) {
		node res;
		res.mx=max(A.mx,B.mx);
		res.cnt=0; res.mx2=max(A.mx2,B.mx2);
		if (A.mx==res.mx) res.cnt+=A.cnt; else res.mx2=max(res.mx2,A.mx);
		if (B.mx==res.mx) res.cnt+=B.cnt; else res.mx2=max(res.mx2,B.mx);
		return res;
	}
} tr[maxn*4];
namespace BIT {
	ll s1[maxn],s2[maxn];
	ll F[maxn];
	void add(int x,ll delta) {
		if (!x) return;
		for (int i=x+1;i<=n;i+=i&(-i)) s1[i]+=delta*x;
		for (int i=x;i;i-=i&(-i)) s2[i]+=delta;
	}
	void add(int l,int r,ll delta) {
	//printf("%d %d %lld\n",l,r,delta);
	//for (int i=l;i<=r;i++) F[i]+=delta;
		add(l-1,-delta),add(r,delta);
	}
	ll query(int x) {
		if (!x) return 0;
		ll res=0;
		for (int i=x;i;i-=i&(-i)) res+=s1[i];
		for (int i=x;i<=n;i+=i&(-i)) res+=s2[i]*x;
		return res;
	}
	ll query(int l,int r) {
//	ll res=0; for (int i=l;i<=r;i++) res+=F[i]; printf("?%lld\n",res);
		return query(r)-query(l-1);
	}
};
void puttag(int root,int delta) {
	if (tr[root].mx>delta) lazy[root]=delta,tr[root].mx=delta;
}
void pushdown(int root) {
	if (lazy[root]!=INF) {
		puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=INF;
	}
}
void pushup(int root) {
	tr[root]=tr[root<<1]+tr[root<<1|1];
}
void build(int l,int r,int root) {
	lazy[root]=INF;
	if (l==r) {
		tr[root].init(l); return;
	}
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void change(int x,int l,int r,int root,int delta) {
	if (l==r) {
		int pre=tr[root].mx;
		if (pre<delta) BIT::add(pre+1,delta,1);
		else if (pre>delta) BIT::add(delta+1,pre,-1);
		tr[root].mx=delta;
		return;
	}
	int mid=(l+r)>>1; pushdown(root);
	if (x<=mid) change(x,l,mid,root<<1,delta);
	else change(x,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void chkmin(int L,int R,int l,int r,int root,int delta) {
	if (tr[root].mx<=delta) return;
	if (L<=l&&r<=R&&tr[root].mx2<=delta) {
		BIT::add(delta+1,tr[root].mx,-tr[root].cnt);
		puttag(root,delta);
		return;
	}
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) chkmin(L,R,l,mid,root<<1,delta);
	if (mid<R) chkmin(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	BIT::add(1,n,1);
	build(1,n,1);
	while (q--) {
		int op; read(op);
		int x,y; read(x),read(y);
		if (op==1) {
			change(x,1,n,1,y);
			if (x>1) chkmin(1,x-1,1,n,1,x-1);
		} else {
			printf("%lld\n",BIT::query(x,y));
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