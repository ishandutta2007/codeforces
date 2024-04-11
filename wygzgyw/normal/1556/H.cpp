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
const int INF=0x7f7f7f7f;
const int maxn=2510;
int n,k,d[60],a[maxn];
int W[60][60],dis[maxn],hd,tl,q[maxn];
int tot; pair<int,int> xyr[60];
vector<int> g[maxn];
int deg[60],ans=INF; bool vis[maxn],in[maxn];
int len[maxn],pre[maxn];
int m,u[maxn],v[maxn],w[maxn];
struct DSU {
	int fa[60];
	void init() { for (int i=1;i<=n;i++) fa[i]=i; }
	int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
	bool merge(int x,int y) {
		x=find(x),y=find(y); if (x==y) return 0;
		fa[x]=y; return 1;
	}
} now,tmp;
void add(int x,int y) { g[x].push_back(y); }
bool solve() {
	for (int i=1;i<=m;i++) dis[i]=INF,len[i]=INF,vis[i]=pre[i]=0,g[i].clear(); hd=1,tl=0;
	tmp=now;
	for (int i=1;i<=m;i++) {
		if (in[i]) tmp.merge(u[i],v[i]),deg[u[i]]++,deg[v[i]]++;
		a[i]=(in[i]?-w[i]:w[i]);
	}
	for (int i=1;i<=m;i++) if (!in[i]&&tmp.find(u[i])!=tmp.find(v[i])) {
		q[++tl]=i,dis[i]=a[i],len[i]=0,vis[i]=1;
		//printf("i=%d\n",i);
	}
	for (int i=1;i<=m;i++) if (in[i]) {
		tmp=now;
		for (int j=1;j<=m;j++) if (in[j]&&i!=j) tmp.merge(u[j],v[j]);
		for (int j=1;j<=m;j++) if (!in[j]&&tmp.find(u[j])!=tmp.find(v[j])) add(i,j);
	}
	for (int i=1;i<=m;i++) if (in[i]) {
		deg[u[i]]--,deg[v[i]]--;
		for (int j=1;j<=m;j++) if (!in[j]&&deg[u[j]]<d[u[j]]&&deg[v[j]]<d[v[j]]) add(j,i);
		deg[u[i]]++,deg[v[i]]++;
	}
	while (hd<=tl) {
		int x=q[hd]; hd++; vis[x]=0;
		for (int &y : g[x]) {
			if (MP(dis[y],len[y])>MP(dis[x]+a[y],len[x]+1)) {
				dis[y]=dis[x]+a[y],len[y]=len[x]+1,pre[y]=x;
				if (!vis[y]) vis[y]=1,q[++tl]=y;
			}
		}
	}
	int fd=0,mn1=INF-1,mn2=INF-1;
	for (int i=1;i<=m;i++) if (!in[i]) {
		if (deg[u[i]]<d[u[i]]&&deg[v[i]]<d[v[i]]) {
			if (MP(mn1,mn2)>MP(dis[i],len[i])) mn1=dis[i],mn2=len[i],fd=i;
		}
	}
	for (int i=1;i<=m;i++) if (in[i]) deg[u[i]]--,deg[v[i]]--;
	if (fd) {
		while (fd) {
			in[fd]^=1;
			fd=pre[fd];
		}
		//for (int i=1;i<=m;i++) if (in[i]) printf("%d ",i); puts("");
		return 1;
	}
	return 0;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	for (int i=1;i<=k;i++) read(d[i]); for (int i=k+1;i<=n;i++) d[i]=INF;
	for (int i=1;i<n;i++) for (int j=i+1;j<=n;j++) read(W[i][j]),W[j][i]=W[i][j];
	for (int i=1;i<=k;i++) for (int j=i+1;j<=k;j++) xyr[++tot]=MP(i,j);
	for (int i=1;i<=n;i++) for (int j=max(i+1,k+1);j<=n;j++) m++,u[m]=i,v[m]=j,w[m]=W[i][j];
	//printf("m=%d\n",m);
	for (int t=0;t<(1<<tot);t++) {
		now.init(); bool flag=1; int cnt=0,sum=0;
		for (int i=1;i<=n;i++) deg[i]=0; for (int j=1;j<=m;j++) in[j]=0;
		for (int i=1;i<=tot;i++) if (t&(1<<(i-1))) {
			int x=xyr[i].first,y=xyr[i].second;
			if (!now.merge(x,y)) { flag=0; break; }
			deg[x]++,deg[y]++; cnt++; sum+=W[x][y];
		}
		for (int i=1;i<=k&&flag;i++) flag&=(deg[i]<=d[i]);
		if (!flag) continue;
		while (solve()) cnt++;
		assert(cnt<=n-1);
		if (cnt==n-1) {
			for (int i=1;i<=m;i++) if (in[i]) sum+=w[i];
			ans=min(ans,sum);
		}
	}
	printf("%d\n",ans);
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