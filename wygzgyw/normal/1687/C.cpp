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
int T,n,m,a[maxn],b[maxn];
ll s[maxn];
int tr[maxn*4];
vector<int> g1[maxn],g2[maxn];
void build(int l,int r,int root) {
	if (l==r) { tr[root]=(s[l]!=0); return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	tr[root]=tr[root<<1]+tr[root<<1|1];
}
void del(int x,int l,int r,int root) {
	if (l==r) { tr[root]=0; return; }
	int mid=(l+r)>>1;
	if (x<=mid) del(x,l,mid,root<<1);
	else del(x,mid+1,r,root<<1|1);
	tr[root]=tr[root<<1]+tr[root<<1|1];
}
vector<int> V;
int query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1,res=0;
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res+=query(L,R,mid+1,r,root<<1|1);
	return res;
}
int hd,tl; pair<int,int> q[maxn];
void dfs(int L,int R,int l,int r,int root) {
	if (!tr[root]) return;
	if (L<=l&&r<=R) {
		if (l==r) { V.push_back(l); return; }
		int mid=(l+r)>>1;
		dfs(L,R,l,mid,root<<1),dfs(L,R,mid+1,r,root<<1|1);
		return;
	}
	int mid=(l+r)>>1;
	if (L<=mid) dfs(L,R,l,mid,root<<1);
	if (mid<R) dfs(L,R,mid+1,r,root<<1|1);
}
void insert(int x,int y) {
	if (s[x-1]==s[y]&&s[y]==0&&query(x,y,0,n,1)) q[++tl]=MP(x,y);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		int m; read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) read(b[i]);
		for (int i=1;i<=n;i++) s[i]=s[i-1]+a[i]-b[i];
		build(0,n,1);
		int x,y; hd=1,tl=0;
		for (int i=0;i<=n;i++) g1[i].clear(),g2[i].clear();
		for (int i=1;i<=m;i++) {
			read(x),read(y); insert(x,y);
			g1[x].push_back(y),g2[y].push_back(x);
		}
		while (hd<=tl) {
			x=q[hd].first,y=q[hd].second; hd++;
			V.clear(); dfs(x,y,0,n,1);
			if ((int)V.size()==0) continue;
			for (int &z : V) del(z,0,n,1),s[z]=0;
			for (int &z : V) for (int &k : g2[z]) insert(k,z);
			for (int &z : V) for (int &k : g1[z+1]) insert(z+1,k);
		}
		if (tr[1]==0) puts("YES"); else puts("NO");
		
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