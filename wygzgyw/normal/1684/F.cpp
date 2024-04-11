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
const int INF=1e9;
const int maxn=(2e5)+10;
int T,n,m;
int a[maxn],lsh[maxn],N;
int mn[maxn];
int tr[maxn*4],lazy[maxn*4];
void puttag(int root,int delta) {
	tr[root]=min(tr[root],delta);
	lazy[root]=min(lazy[root],delta);
}
void pushdown(int root) {
	puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=INF;
}
void dfs(int l,int r,int root) {
	if (l==r) { mn[l]=tr[root]; return; }
	int mid=(l+r)>>1;
	pushdown(root);
	dfs(l,mid,root<<1);
	dfs(mid+1,r,root<<1|1);
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	pushdown(root); int mid=(l+r)>>1;
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	tr[root]=min(tr[root<<1],tr[root<<1|1]);
}
vector<int> g[maxn];
int pos[maxn],bad[maxn];
int A[maxn],B[maxn];
int query(int l,int i) {
	i=a[i];
	int x=lower_bound(g[i].begin(),g[i].end(),l)-g[i].begin();
	return g[i][x];
}
int Nxt(int x) {
	return g[a[x]][pos[x]+1];
}
int pre[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) {
			read(a[i]); lsh[++N]=a[i];
		}
		sort(lsh+1,lsh+N+1),N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh;
		for (int i=1;i<=N;i++) g[i].clear();
		for (int i=1;i<=n;i++) {
			g[a[i]].push_back(i);
			pos[i]=(int)g[a[i]].size()-1;
		}
		for (int i=1;i<=n*4;i++) tr[i]=lazy[i]=1e9;
		for (int i=1;i<=m;i++) {
			int l,r;
			read(l),read(r);
			add(l,r,1,n,1,l);
		}
		dfs(1,n,1);
		int flag=0,ans=1e9;
		for (int i=1;i<=n+1;i++) bad[i]=0,A[i]=B[i]=1e9;
		for (int i=1;i<=n;i++) {
			if (pos[i]!=0&&g[a[i]][pos[i]-1]>=mn[i]) {
				bad[g[a[i]][pos[i]-1]]=1,flag=1;
				B[i]=query(mn[i],i);
			//	printf("> %d %d\n",i,B[i]);
				A[i]=Nxt(B[i]);
			}
		}
		if (!flag) { puts("0"); continue; }
		int L=n+1;
		pre[0]=1e9;
		for (int i=1;i<=n;i++) {
			pre[i]=min(pre[i-1],A[i]);
		}
		for (int i=n;i>=1;i--) {
			if (bad[i+1]) break;
			L=min(L,B[i+1]);
			//printf("%d %d\n",i,min(L,pre[i]));
			ans=min(ans,i-min(L,pre[i])+1);
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