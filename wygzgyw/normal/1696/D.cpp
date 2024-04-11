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
const int maxn=250010;
const int INF=0x7f7f7f7f;
int T,n;
int dp[maxn],p[maxn];
int s1[maxn],t1,s2[maxn],t2;
struct Tree {
	int tr[maxn*4];
	void init() { for (int i=1;i<=n*4;i++) tr[i]=INF; }
	int query(int L,int R,int l,int r,int root) {
		if (L>R) return INF;
		if (L<=l&&r<=R) return tr[root];
		int mid=(l+r)>>1,res=INF;
		if (L<=mid) res=query(L,R,l,mid,root<<1);
		if (mid<R) res=min(res,query(L,R,mid+1,r,root<<1|1));
		return res;
	}
	void add(int x,int l,int r,int root,int delta) {
		if (l==r) { tr[root]=delta; return; }
		int mid=(l+r)>>1;
		if (x<=mid) add(x,l,mid,root<<1,delta);
		else add(x,mid+1,r,root<<1|1,delta);
		tr[root]=min(tr[root<<1],tr[root<<1|1]);
	}
	void insert(int x,int delta) {
		add(x,1,n,1,delta);
	}
} T1,T2;
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(p[i]);
		t1=0,t2=0,T1.init(),T2.init();
		for (int i=1;i<=n;i++) {
			while (t1&&p[s1[t1]]<p[i]) T1.insert(s1[t1],INF),t1--;
			while (t2&&p[s2[t2]]>p[i]) T2.insert(s2[t2],INF),t2--;
			if (i>1) {
				dp[i]=min(T1.query(s2[t2]+1,i-1,1,n,1),T2.query(s1[t1]+1,i-1,1,n,1))+1;
			}
			s1[++t1]=i,s2[++t2]=i;
			T1.insert(i,dp[i]),T2.insert(i,dp[i]);
		}
		printf("%d\n",dp[n]);
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