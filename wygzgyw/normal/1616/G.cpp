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
const int maxn=(1.5e5)+10;
int T,n,a[maxn*3],b[maxn*3],m,d[maxn][2];
bool c[maxn];
int sum[maxn];
vector<int> g[maxn],h[maxn];
void add(int x,int y) { g[x].push_back(y),h[y].push_back(x); }
void dfs(int u,int p,vector<int> *g) {
	if (d[u][p]) return; d[u][p]=1;
	for (int &x : g[u]) dfs(x,p^1,g);
}
int cnt[2][2];
int main() {
	read(T); while (T--) {
		read(n),read(m);
		for (int i=0;i<=n+1;i++) g[i].clear(),h[i].clear(),d[i][0]=d[i][1]=0,c[i]=0;
		memset(cnt,0,sizeof(cnt));
		for (int i=0;i<=n;i++) c[i]=1;
		for (int i=1;i<=m;i++) {
			read(a[i]),read(b[i]);
			if (a[i]+1==b[i]) c[a[i]]=0;
		}
		c[0]=c[n]=0;
		for (int i=1;i<=n;i++) a[++m]=0,b[m]=i,a[++m]=i,b[m]=n+1;
		int x=n+1,y=0;
		for (int i=1;i<=n;i++) {
			if (c[i]) x=min(x,i),y=max(y,i);
		}
		if (!y) { printf("%lld\n",(ll)n*(n-1)/2); continue; }
		for (int i=0;i<=n;i++) sum[i]=(i==0?0:sum[i-1])+c[i];
		for (int i=1;i<=m;i++)
			if (a[i]<b[i]-1&&sum[a[i]]==sum[b[i]-2]) add(a[i],b[i]-1);
		ll ans=0;
		dfs(x,0,g);
		d[x][0]=0; dfs(x,0,h);
		for (int i=0;i<=x;i++) cnt[d[i][0]][d[i][1]]++;
		for (int i=y;i<=n;i++) {
			for (int j=0;j<2;j++) for (int k=0;k<2;k++)
				if ((j&&d[i][0])||(k&&d[i][1])) ans+=cnt[j][k];
		}
		printf("%lld\n",ans-(x==y));
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