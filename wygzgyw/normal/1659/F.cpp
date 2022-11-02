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
int T,n,deg[maxn];
int p[maxn],vis[maxn],cnt;
int sp,q[maxn];
int main() {
	read(T);
	while (T--) {
		read(n); read(sp);
		for (int i=1;i<=n;i++) deg[i]=vis[i]=0;
		int x,y;
		for (int i=1;i<n;i++) read(x),read(y),deg[x]++,deg[y]++;
		int flag=1;
		for (int i=1;i<=n;i++) read(p[i]),flag&=(p[i]==i),q[p[i]]=i;
		int m=0;
		for (int i=1;i<=n;i++) if (deg[i]==n-1) { m=i; break; }
		if (flag||!m) { puts("Alice"); continue; }
		cnt=0;
		int X=0,Y=0;
		for (int i=1;i<=n;i++) if (p[i]!=i) { cnt++; if (!X) X=i; else Y=i; }
		if (cnt==2&&sp!=X&&sp!=Y) { puts("Alice"); continue; }	
		if (p[m]!=m&&(sp==m||sp==p[m])) { puts("Bob"); continue; }
		if (p[m]!=m) {
			x=q[m];
			swap(p[x],p[m]);
			sp=m;
		}
		cnt=0;
		for (int i=1;i<=n;i++) if (!vis[i]) {
			int x=i; while (1) { vis[x]=1; if (p[x]==i) break; x=p[x]; }
			cnt++;
		}
		if (sp!=m) cnt++;
		if ((n-cnt)&1) puts("Alice");
		else puts("Bob");
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