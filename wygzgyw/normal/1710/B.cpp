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
const ll INF=1e18;
const int maxn=(1e6)+10;
int T,n;
pair<ll,ll> d[maxn];
int tot;
ll m;
ll X[maxn],P[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m); tot=0;
		for (int i=1;i<=n;i++) {
			int x,p; read(x),read(p);
			X[i]=x,P[i]=p;
			d[++tot]=MP(x-p,1);
			d[++tot]=MP(x,-2);
			d[++tot]=MP(x+p,1);
		}
		sort(d+1,d+tot+1);
		ll pre=0,now=0;
		ll m1=-INF,m2=-INF;
		for (int i=1;i<tot;i++) {
			pre+=d[i].second;
			now+=(d[i+1].first-d[i].first)*pre;
			if (now>m) {
				m1=max(m1,now-m+d[i+1].first);
				m2=max(m2,now-m-d[i+1].first);
			}
		}
		for (int i=1;i<=n;i++)
			if (X[i]+P[i]>=m1&&P[i]-X[i]>=m2) putchar('1'); else putchar('0');
		puts("");
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