#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e7)+10;
int n,q,a[200010];
int rt,tot,N;
int ls[maxn],rs[maxn];
int lazy[maxn];
int And[maxn],Or[maxn],tr[maxn];
void pushup(int root) {
	And[root]=And[ls[root]]|And[rs[root]];
	Or[root]=Or[ls[root]]|Or[rs[root]];
	tr[root]=tr[ls[root]]+tr[rs[root]];
}
void insert(int dep,int &root,int x) {
	if (!root) root=++tot;
	if (dep==0) { tr[root]=1; And[root]=N-x,Or[root]=x; return; }
	if (x>>(dep-1)&1) insert(dep-1,rs[root],x);
	else insert(dep-1,ls[root],x);
	pushup(root);
}
void update_xor(int dep,int root,int x) {
	if (root==0) return;
	//printf("%d %d %d\n",dep,root,x);
	if (x>>(dep-1)&1) swap(ls[root],rs[root]);
	int A=And[root],O=Or[root];
	And[root]=(A&(N-x))|(O&x);
	Or[root]=(O&(N-x))|(A&x);
	lazy[root]^=x;
}
void pushdown(int dep,int root) {
	if (lazy[root]==0) return;
	update_xor(dep-1,ls[root],lazy[root]);
	update_xor(dep-1,rs[root],lazy[root]);
	lazy[root]=0;
}
void merge(int dep,int &x,int &y) {
	//printf("%d %d %d,%d %d\n",dep,x,y,ls[x],rs[x]);
	if (!x) { x=y; return; }
	if (!y||!dep) return;
	pushdown(dep,x),pushdown(dep,y);
	merge(dep-1,ls[x],ls[y]);
	merge(dep-1,rs[x],rs[y]);
	pushup(x);
}
int query(int dep,int L,int R,int l,int r,int root) {
	if (!root) return 0;
	if (L<=l&&r<=R) return tr[root];
	pushdown(dep,root);
	int mid=(l+r)>>1,res=0;
	if (L<=mid) res=query(dep-1,L,R,l,mid,ls[root]);
	if (mid<R) res+=query(dep-1,L,R,mid+1,r,rs[root]);
	return res;
}
void update_or(int dep,int root,int x) {
	if (!root) return;
	if ((x&And[root]&Or[root])==0) {
		update_xor(dep,root,x&And[root]);
		return;
	}
	pushdown(dep,root);
	if (x>>(dep-1)&1) {
		update_xor(dep-1,ls[root],1<<(dep-1));
		merge(dep-1,rs[root],ls[root]);
		ls[root]=0;
	}
	update_or(dep-1,ls[root],x);
	update_or(dep-1,rs[root],x);
	pushup(root);
}
void split(int dep,int L,int R,int &x,int &y,int l,int r) {
	if (x==0||l>R||r<L) { y=0; return; }
	if (L<=l&&r<=R) { y=x; x=0; return; }
	int mid=(l+r)>>1;
	pushdown(dep,x); y=++tot;
	split(dep-1,L,R,ls[x],ls[y],l,mid);
	split(dep-1,L,R,rs[x],rs[y],mid+1,r);
	pushup(x),pushup(y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q); N=(1<<20)-1;
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) insert(20,rt,a[i]);
	int op,l,r,x;
	while (q--) {
		read(op),read(l),read(r);
		if (op==4) {
			printf("%d\n",query(20,l,r,0,N,rt));
			continue;
		}
		read(x); int now;
		split(20,l,r,rt,now,0,N);
		if (op==1) update_xor(20,now,N),update_or(20,now,N-x),update_xor(20,now,N);
		else if (op==2) update_or(20,now,x);
		else update_xor(20,now,x);
		merge(20,rt,now);
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