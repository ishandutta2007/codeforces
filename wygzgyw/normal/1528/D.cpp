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
typedef long long ll;
const int INF=0x7f7f7f7f;
const int maxn=610;
int n,m,f[maxn][maxn];
ll dis[maxn];
int d[maxn][maxn];
bool vis[maxn];
void update(int &x,int y) { if (x>y) x=y; }
priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > > q;
int main() {
//	freopen("1.txt","r",stdin);
	read(n),read(m); int a,b,c;
	memset(d,INF,sizeof(d));
	memset(f,INF,sizeof(f));
	for (int i=1;i<=m;i++) {
		read(a),read(b),read(c);
		d[a][b]=min(d[a][b],c);
	}
	for (int a=0;a<n;++a) {
		for (int k=0;k<n;++k) if (d[a][k]!=INF) {
			for (int bt=0;bt<n;++bt) update(f[a][bt],d[a][k]+(bt-k+n)%n);
		}
	} ll tmp;
	for (int a=0;a<n;a++) {
		for (int b=0;b<n;b++) dis[b]=(1e18),vis[b]=0;
		dis[a]=0; q.push(make_pair(0LL,a));
		while (!q.empty()) {
			b=q.top().second; q.pop(); if (vis[b]) continue; vis[b]=1;
			for (int c=0;c<n;c++) if (!vis[c]) {
				tmp=f[b][(c-dis[b]%n+n)%n];
				if (tmp==INF) continue;
				tmp+=dis[b];
				if (tmp<dis[c]) dis[c]=tmp,q.push(make_pair(tmp,c));
			}
		}
		for (int b=0;b<n;b++) printf("%lld ",dis[b]); puts("");
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