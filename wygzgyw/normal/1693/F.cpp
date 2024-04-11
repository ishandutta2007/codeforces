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
int T;
char s[maxn];
int n,mx[maxn],pre0[maxn],sum[maxn];
int main() {
	read(T);
	while (T--) {
		read(n); scanf("%s",s+1);
		int flag=1; for (int i=1;i<n;i++) flag&=(s[i]<=s[i+1]);
		if (flag) { puts("0"); continue; }
		int c0=0,c1=0;
		for (int i=1;i<=n;i++) if (s[i]=='0') c0++; else c1++;
		if (c0<c1) { for (int i=1;i<=n;i++) s[i]='0'+'1'-s[i]; reverse(s+1,s+n+1); swap(c0,c1); }
		for (int i=0;i<=n;i++) mx[i]=0;
		for (int i=1;i<=n;i++) {
			sum[i]=sum[i-1];
			if (s[i]=='0') sum[i]++; else sum[i]--; if (sum[i]>=0) mx[sum[i]]=i;
			pre0[i]=pre0[i-1]; if (s[i]=='0') pre0[i]++;
		}
		int delta=c0-c1;
		int pos=0;
		while (s[pos+1]=='0') pos++;
		int ans=0;
		while (pre0[pos]<delta) {
			int nxt=mx[pre0[pos]];
			pos=nxt; ans++;
		}
		printf("%d\n",ans+1);
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