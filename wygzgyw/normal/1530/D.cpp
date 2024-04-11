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
int T,n,b[maxn],a[maxn];
bool vis[maxn];
vector<int> g;
bool solve() {
	g.clear();
	for (int i=1;i<=n;i++) if (!vis[i]&&!b[i]) g.push_back(i);
	if ((int)g.size()==1) {
		for (int i=1;i<=n;i++) if (!vis[i]&&i!=g[0]) {
			b[g[0]]=i; vis[i]=1; break;
		}
		if (!b[g[0]]) return 0;
		int pos=1;
		for (int i=1;i<=n;i++) if (!b[i]) {
			while (vis[pos]) pos++; b[i]=pos; vis[pos]=1;
		}
		return 1;
	}
	
	for (int i=0;i<g.size();i++) b[g[i]]=g[(i+1)%(int)g.size()],vis[b[g[i]]]=1;
	int pos=1;
	for (int i=1;i<=n;i++) if (!b[i]) {
		while (vis[pos]) pos++; b[i]=pos; vis[pos]=1;
	}
	return 1;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		int ans=0;
		read(n);
		for (int i=1;i<=n;i++) vis[i]=0,b[i]=0;
		for (int i=1;i<=n;i++) {
			read(a[i]);
			if (!vis[a[i]]) {
				b[i]=a[i];
			}
			vis[a[i]]=1;
		}
		if (solve()) {
			for (int i=1;i<=n;i++) ans+=(b[i]==a[i]); printf("%d\n",ans);
			for (int i=1;i<=n;i++) printf("%d ",b[i]); puts(""); continue;
		}
		int fd=-1;
		for (int i=1;i<=n;i++) if (a[i]==a[g[0]]) { fd=i; break; }
		b[fd]=g[0],b[g[0]]=a[g[0]];
		vis[b[fd]]=vis[a[g[0]]]=1;
		int pos=1;
		for (int i=1;i<=n;i++) if (!b[i]) {
			while (vis[pos]) pos++; b[i]=pos; vis[pos]=1;
		}
		for (int i=1;i<=n;i++) ans+=(b[i]==a[i]); printf("%d\n",ans);
		for (int i=1;i<=n;i++) printf("%d ",b[i]); puts("");
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