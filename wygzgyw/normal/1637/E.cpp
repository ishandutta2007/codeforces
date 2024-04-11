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
int T,n,m,cnt[maxn];
vector<int> g[maxn],vec[maxn];
int vis[maxn],tim;
int a[maxn],lsh[maxn],N;
int d[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m); N=0; int x,y;
		for (int i=1;i<=n;i++) read(a[i]),lsh[++N]=a[i];
		sort(lsh+1,lsh+N+1); N=unique(lsh+1,lsh+N+1)-lsh-1;
		for (int i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+N+1,a[i])-lsh,cnt[a[i]]++;
		for (int i=1;i<=m;i++) {
			read(x),read(y);
			x=lower_bound(lsh+1,lsh+N+1,x)-lsh;
			y=lower_bound(lsh+1,lsh+N+1,y)-lsh;
			g[x].push_back(y); g[y].push_back(x);
		}
		tim=0; d[0]=0;
		int block=800;
		for (int i=N;i>=1;i--) if (cnt[i]>block) d[++d[0]]=i; else vec[cnt[i]].push_back(i);
		ll ans=0;
		//for (int i=1;i<=n;i++) printf("%d ",a[i]); puts("");
		for (int i=1;i<=N;i++) {
			tim++;
			for (int &j : g[i]) vis[j]=tim;
			for (int j=1;j<=d[0];j++) {
				int y=d[j]; if (vis[y]!=tim&&y!=i) ans=max(ans,(ll)(cnt[i]+cnt[y])*(lsh[i]+lsh[y]));
			}
			for (int j=1;j<=block;j++) {
				for (int &k : vec[j]) if (vis[k]==tim||k==i); else { ans=max(ans,(ll)(cnt[i]+cnt[k])*(lsh[i]+lsh[k])); break; }
			}
		}
		printf("%lld\n",ans);
		for (int i=1;i<=N;i++) cnt[i]=0,g[i].clear(),vis[i]=0,vec[i].clear();
		
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