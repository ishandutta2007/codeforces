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
const int maxn=(2e5)+10;
const int INF=(1e9);
int p[maxn],n,T,tr[maxn*4],lazy[maxn*4];
int rem[maxn],vis[maxn];
void puttag(int root,int delta) {
	lazy[root]+=delta,tr[root]+=delta;
}
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void pushup(int root) { tr[root]=max(tr[root<<1],tr[root<<1|1]); }
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	pushdown(root); int mid=(l+r)>>1;
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int main() {
	read(T);
	while (T--) {
		read(n); int flag=1;
		for (int i=1;i<=n;i++) read(p[i]),flag&=(p[i]==i),vis[i]=0;
		if (flag) { puts("0"); continue; }
		for (int i=1;i<n;i+=2) if (p[i]>p[i+1]) swap(p[i],p[i+1]);
		for (int i=1;i<=n;i++) rem[p[i]]=i;
		for (int i=1;i<=n*4;i++) tr[i]=-INF,lazy[i]=0;
		// n-hou[i]+1-i+qian[i])
		int ans=1,lst=n;
		for (int i=n;i>=2;i--) {
			int x=rem[i];
			vis[x]=1;
			add(x,x,1,n,1,INF-x);
			add(x,n,1,n,1,1);
			add(1,x,1,n,1,-1);
			while (vis[lst]) add(lst,lst,1,n,1,-INF),lst--;
			ans=max(ans,tr[1]+n+1);
//			for (int j=1;j<=n;j++) printf("%d ",p[j]>=i); printf(" %d %d\n",lst,tr[1]+n+1);
		}
		printf("%d\n",ans);
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