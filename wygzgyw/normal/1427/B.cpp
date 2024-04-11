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
int T,n,k,d[maxn],buc[maxn];
char s[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		scanf("%s",s+1);
		int ans=0,tot=0,c0=0;
		for (int i=1;i<=n;i++) {
			if (s[i]=='W') ans++,d[++tot]=i; else c0++;
			if (s[i-1]=='W'&&s[i]=='W') ans++;
		}
		if (!k) { printf("%d\n",ans); continue; }
		if (c0==n) { printf("%d\n",k*2-1); continue; }
		int cnt=0;
		for (int i=2;i<=tot;i++) if (d[i]!=d[i-1]+1) buc[++cnt]=d[i]-d[i-1]-1;
		sort(buc+1,buc+cnt+1);
		ans+=min(k,c0)*2;
		for (int i=1;i<=cnt;i++) {
			if (k>=buc[i]) ans++,k-=buc[i];
		}
		printf("%d\n",ans);
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