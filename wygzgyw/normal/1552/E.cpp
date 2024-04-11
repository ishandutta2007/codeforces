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
int n,k,c[10010],pre[10010],lst[110];
int ans[110][2],cnt[10010];
int main() {
	read(n),read(k);
	for (int i=1;i<=n*k;i++) {
		read(c[i]);
		pre[i]=lst[c[i]];
		lst[c[i]]=i;
	}
	for (int i=1;i<=n*k;i++) if (pre[i]&&!ans[c[i]][0]) {
		int mx=0;
		for (int j=pre[i];j<=i;j++) mx=max(mx,cnt[j]);
		if (mx<(n-1)/(k-1)+1) {
			ans[c[i]][0]=pre[i],ans[c[i]][1]=i;
			for (int j=pre[i];j<=i;j++) cnt[j]++;
		}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",ans[i][0],ans[i][1]);
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