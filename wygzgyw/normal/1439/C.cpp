#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
int n,q,a[maxn],mn[maxn*4],sz[maxn*4];
ll sum[maxn*4],lazy[maxn*4];
void pushup(int root) {
	sum[root]=sum[root*2]+sum[root*2+1];
	mn[root]=min(mn[root*2],mn[root*2+1]);
}
void puttag(int root,ll delta) {
	mn[root]=delta,sum[root]=delta*sz[root],lazy[root]=max(lazy[root],delta);
}
void pushdown(int root) {
	if (lazy[root]) {
		puttag(root*2,lazy[root]);
		puttag(root*2+1,lazy[root]);
		lazy[root]=0;
	}
}
void build(int l,int r,int root) {
	sz[root]=r-l+1;
	if (l==r) { sum[root]=mn[root]=a[l]; return; }
	int mid=(l+r)/2;
	build(l,mid,root*2),build(mid+1,r,root*2+1);
	pushup(root);
}
void update(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		if (delta>mn[root]) puttag(root,delta);
		return;
	}
	int mid=(l+r)/2;
	pushdown(root);
	if (L<=mid) update(L,R,l,mid,root*2,delta);
	if (mid<R) update(L,R,mid+1,r,root*2+1,delta);
	pushup(root);
}
void add(int x,int l,int r,int root,int delta) {
	if (l==r) {
		if (mn[root]<=delta&&l<=x) update(l,x,1,n,1,delta);
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (mn[root*2]<=delta) add(x,l,mid,root*2,delta);
	else add(x,mid+1,r,root*2+1,delta);
}
int query(int x,int l,int r,int root,int &delta) {
	if (delta<mn[root]||r<x) return 0;
	if (l==r) { delta-=sum[root]; return 1; }
	if (l>=x&&sum[root]<=delta) { delta-=sum[root]; return r-l+1; }
	pushdown(root);
	int mid=(l+r)/2;
	return query(x,l,mid,root*2,delta)+query(x,mid+1,r,root*2+1,delta);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	build(1,n,1);
	int op,x,y;
	while (q--) {
		read(op),read(x),read(y);
		if (op==1) add(x,1,n,1,y);
		else printf("%d\n",query(x,1,n,1,y));
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/