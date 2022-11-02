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
const int maxm=(1e6)+10;
const int maxn=(2e5)+10;
int T,n,a[maxn],m; ll ans;
struct node { int x,y; } nxt[maxn];
bool vis[maxm]; int prime[maxm],tot;
int main() {
	for (int i=2;i<maxm;i++) {
		if (!vis[i]) prime[++tot]=i;
		for (int j=1;j<=tot&&prime[j]*i<maxm;j++) {
			vis[prime[j]*i]=1; if (i%prime[j]==0) break;
		}
	}
	read(T); while (T--) {
		read(n); read(m);
		for (int i=1;i<=n;i++) read(a[i]); ans=0;
		for (int i=n;i>=1;i--) {
			nxt[i]=(node){i+m,i+m};
			if (i+m<=n) {
				if (a[i]!=1) nxt[i]=(node){i,nxt[i+m].x};
				else nxt[i]=nxt[i+m];
			} else {
				if (a[i]!=1) nxt[i]=(node){i,i+m};
			}
			//printf("%d %d\n",nxt[i].x,nxt[i].y);
			if (nxt[i].x<=n&&!vis[a[nxt[i].x]]) {
				ans+=(nxt[i].y-nxt[i].x)/m; if (nxt[i].x==i) ans--;
			}
		}
		printf("%lld\n",ans);
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