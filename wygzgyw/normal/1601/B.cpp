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
const int maxn=(3e5)+10;
const int INF=1e9;
int n,a[maxn],b[maxn],dp[maxn];
vector<int> g[maxn];
int from[maxn],tr[maxn*4];
vector<int> ans;
queue<int> q;
void add(int x,int l,int r,int root,int delta) {
	if (l==r) { tr[root]=delta; return; }
	int mid=(l+r)>>1;
	if (x<=mid) add(x,l,mid,root<<1,delta);
	else add(x,mid+1,r,root<<1|1,delta);
	tr[root]=min(tr[root<<1],tr[root<<1|1]);
} bool mk[maxn];
void insert(int x,int d,int f) {
	if (dp[x]>d) {
		dp[x]=d;
		from[x]=f;
		q.push(x);
		if (!mk[x]) mk[x]=1,add(x,1,n,1,INF);
	}
}
void query(int L,int R,int l,int r,int root,int delta,int d,int f) {
	if (tr[root]>delta) return;
	int mid=(l+r)>>1;
	if (L<=l&&r<=R) {
		if (l==r) insert(l,d,f);
		else query(L,R,l,mid,root<<1,delta,d,f),query(L,R,mid+1,r,root<<1|1,delta,d,f);
		return;
	}
	if (L<=mid) query(L,R,l,mid,root<<1,delta,d,f);
	if (mid<R) query(L,R,mid+1,r,root<<1|1,delta,d,f);
}
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=1;i<=n;i++) dp[i]=INF;
	for (int i=1;i<=n;i++) g[i+b[i]].push_back(i),add(i,1,n,1,i-a[i]);
	for (int i=1;i<=n;i++) if (i-a[i]<=0) insert(i,1,0);
	while (!q.empty()) {
		int x=q.front(); q.pop();
		for (int &j : g[x]) {
			query(j,n,1,n,1,j,dp[x]+1,j);
		}
	}
	if (dp[n]==INF) puts("-1");
	else {
		int pos=n;
		while (pos) {
			ans.push_back(from[pos]);
			pos=from[pos]; pos+=b[pos];
		}
		printf("%d\n",(int)ans.size());
		for (int &x : ans) printf("%d ",x); puts("");
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