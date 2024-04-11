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
const int maxn=(1e5)+10;
int T,n;
char s[maxn],t[maxn],ans[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),scanf("%s",s+1);
		if (s[1]!='9') {
			for (int i=1;i<=n;i++) printf("%d",9-(s[i]-'0')); puts(""); continue;
		}
		reverse(s+1,s+n+1);
		n++;
		for (int i=1;i<=n;i++) t[i]='0';
		t[1]=t[n]='1';
		t[2]=t[n-1]='8';
		int r=0;
		for (int i=1;i<=n;i++) {
			int v=(t[i]-'0')-(s[i]-'0')-r;
			if (v<0) r=1,v+=10; else r=0;
			ans[i]=v+'0';
		}
		ans[n]=0;
		reverse(ans+1,ans+n);
		printf("%s\n",ans+1);
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