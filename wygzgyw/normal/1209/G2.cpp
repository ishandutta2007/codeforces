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
const int maxn=(8e5)+10;
int n,q,a[maxn],d[maxn];
set<int> s[maxn];
int len[maxn],cnt[maxn],ans[maxn];
int lazy[maxn],mx[maxn];
int mn[maxn],L[maxn],R[maxn];
void pushup(int root) {
	mx[root]=max(mx[root<<1],mx[root<<1|1]);
	mn[root]=min(mn[root<<1],mn[root<<1|1]);
	if (mn[root]==mn[root<<1]) L[root]=L[root<<1]; else L[root]=max(mx[root<<1],L[root<<1|1]);
	if (mn[root]==mn[root<<1|1]) R[root]=R[root<<1|1]; else R[root]=max(mx[root<<1|1],R[root<<1]);
	
	if (mn[root]!=mn[root<<1|1]) ans[root]=ans[root<<1],cnt[root]=cnt[root<<1]+len[root<<1|1];
	else if (mn[root]!=mn[root<<1]) ans[root]=ans[root<<1|1],cnt[root]=cnt[root<<1|1]+len[root<<1];
	else {
		ans[root]=ans[root<<1]+ans[root<<1|1],cnt[root]=cnt[root<<1]+cnt[root<<1|1];
		if (R[root<<1]!=-1||L[root<<1|1]!=-1)
			ans[root]+=max(R[root<<1],L[root<<1|1]),cnt[root]++;
	}
}
void build(int l,int r,int root) {
	len[root]=r-l+1; L[root]=R[root]=-1;
	if (l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void pushdown(int root) {
	if (lazy[root]) {
		mn[root<<1]+=lazy[root],mn[root<<1|1]+=lazy[root];
		lazy[root<<1]+=lazy[root],lazy[root<<1|1]+=lazy[root]; lazy[root]=0;
	}
}
void update(int x,int l,int r,int root) {
	if (l==r) {
		mx[root]=max(d[x],d[x+1]); return;
	}
	pushdown(root); int mid=(l+r)>>1;
	if (x<=mid) update(x,l,mid,root<<1);
	else update(x,mid+1,r,root<<1|1);
	pushup(root);
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) {
		mn[root]+=delta; lazy[root]+=delta; return;
	}
	pushdown(root);
	int mid=(l+r)>>1;
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
void update(int x) {
	update(x-1,0,n,1);
	update(x,0,n,1);
}
void del(int x) {
	int l=*s[a[x]].begin(),r=*s[a[x]].rbegin();
	add(l,r-1,0,n,1,-1);
	d[l]=0; update(l);
	s[a[x]].erase(x);
	if (!s[a[x]].empty()) {
		l=*s[a[x]].begin(),r=*s[a[x]].rbegin();
		d[l]=(int)s[a[x]].size(); add(l,r-1,0,n,1,1); update(l);
	}
}
void insert(int x) {
	if (!s[a[x]].empty()) {
		int l=*s[a[x]].begin(),r=*s[a[x]].rbegin();
		add(l,r-1,0,n,1,-1);
		d[l]=0; update(l);
	}
	s[a[x]].insert(x);
	int l=*s[a[x]].begin(),r=*s[a[x]].rbegin();
	add(l,r-1,0,n,1,1);
	d[l]=(int)s[a[x]].size(); update(l);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]);
	build(0,n,1);
	for (int i=1;i<=n;i++) insert(i);
	printf("%d\n",cnt[1]-ans[1]);
	int x,y;
	while (q--) {
		read(x),read(y);
		del(x); a[x]=y; insert(x);
		printf("%d\n",cnt[1]-ans[1]);
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