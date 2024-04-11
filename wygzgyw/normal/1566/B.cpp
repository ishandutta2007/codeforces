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
char s[maxn];
int main() {
	read(T);
	while (T--) {
		scanf("%s",s+1); n=strlen(s+1);
		int flag=1,l=n+1,r=0,cnt=0;
		for (int i=1;i<=n;i++) {
			flag&=(s[i]==s[1]);
			if (s[i]=='0') l=min(l,i),r=max(r,i),cnt++;
		}
		if (flag) {
			if (s[1]=='1') puts("0");
			else puts("1");
			continue;
		}
		if (cnt==r-l+1) puts("1");
		else puts("2");
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