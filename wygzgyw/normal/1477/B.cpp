#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int T,n,m;
int tr[maxn*4],lazy[maxn*4];
char s[maxn],t[maxn];
int sz[maxn*4];
void pushup(int root) { tr[root]=tr[root<<1]+tr[root<<1|1]; }
void build(int l,int r,int root) {
	lazy[root]=-1; sz[root]=r-l+1;
	if (l==r) { tr[root]=t[l]-'0'; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void puttag(int root,int delta) {
	tr[root]=delta*sz[root];
	lazy[root]=delta;
}
void pushdown(int root) {
	if (lazy[root]==-1) return;
	puttag(root<<1,lazy[root]);
	puttag(root<<1|1,lazy[root]);
	lazy[root]=-1;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1; pushdown(root);
	int res=0;
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res+=query(L,R,mid+1,r,root<<1|1);
	return res;
}
int flag;
void dfs(int l,int r,int root) {
	if (l==r) {
		if (tr[root]!=s[l]-'0') { flag=0; return; }
		return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	dfs(l,mid,root<<1);
	dfs(mid+1,r,root<<1|1);
}
int l[maxn],r[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	int tmp;
	read(T);
	while (T--) {
		read(n),read(m);
		scanf("%s",s+1);
		scanf("%s",t+1);
		build(1,n,1);
		for (int i=1;i<=m;i++) read(l[i]),read(r[i]);
		flag=1;
		for (int i=m;i>=1;i--) {
			tmp=query(l[i],r[i],1,n,1);
			if (tmp*2==r[i]-l[i]+1) { flag=0; break; }
			if (tmp*2>r[i]-l[i]+1) add(l[i],r[i],1,n,1,1);
			else add(l[i],r[i],1,n,1,0);
		}
		dfs(1,n,1);
		if (flag) puts("YES");
		else puts("NO");
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