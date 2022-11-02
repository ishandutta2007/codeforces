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
const int maxn=(3e5)+10;
int n,q;
int p[maxn],tot,st[maxn],fa[maxn];
int f[maxn][20];
int dep[maxn]; vector<int> g[maxn];
ll a[maxn],b[maxn],c[maxn],dp[maxn],d[maxn];
set<int> s;
ll ans;
int cnt[maxn];
int lca(int x,int y) {
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=19;i>=0;i--) if (dep[f[x][i]]>=dep[y]) x=f[x][i];
	if (x==y) return x;
	for (int i=19;i>=0;i--) if (f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return fa[x];
}
set<int>::iterator it1,it2;
int l,r;
ll DIS(int x,int y) { return d[x]+d[y]-2*d[lca(x,y)]; }
void add(int x) {
	s.insert(x);
	it1=s.find(x);
	it1--,l=(*it1);
	it1++,it1++;
	if (it1==s.end()) r=0; else r=(*it1);
	ans-=DIS(l,r);
	ans+=DIS(l,x)+DIS(x,r);
}
void del(int x) {
	it1=s.find(x);
	it1--,l=(*it1);
	it1++,it1++;
	if (it1==s.end()) r=0; else r=(*it1);
	ans+=DIS(l,r);
	ans-=DIS(l,x)+DIS(x,r);
	s.erase(x);
}
bool in[maxn];
int main() {
	read(n),read(q);
	for (int i=1;i<=n;i++) read(p[i]);
	for (int i=1;i<=n;i++) {
		while (tot&&p[st[tot]]<p[i]) tot--;
		fa[i]=st[tot],st[++tot]=i;
	}
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	for (int i=0;i<=n;i++) f[i][0]=fa[i];
	for (int i=1;i<=19;i++) for (int j=0;j<=n;j++) f[j][i]=f[f[j][i-1]][i-1];
	dep[0]=1;
	for (int i=1;i<=n;i++) dep[i]=dep[fa[i]]+1;
	for (int i=1;i<=n;i++) c[fa[i]]+=b[i];
	for (int i=1;i<=n;i++) c[i]+=-b[i]+a[i];
	for (int i=n;i>=0;i--) {
		dp[i]+=c[i];
		if (i) dp[fa[i]]+=min(0LL,dp[i]);
	}
	for (int i=0;i<=n;i++) d[i]=max(0LL,dp[i]);
	for (int i=1;i<=n;i++) d[i]+=d[fa[i]];
	s.insert(0); cnt[0]=1;
	while (q--) {
		int x; read(x);
		if (!in[x]) {
			in[x]=1;
			cnt[fa[x]]++;
			if (cnt[fa[x]]==1) add(fa[x]);
		} else {
			in[x]=0;
			cnt[fa[x]]--;
			if (cnt[fa[x]]==0) del(fa[x]);
		}
		printf("%lld\n",ans/2+dp[0]);
	}
	return 0;
}