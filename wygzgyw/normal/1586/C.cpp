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
const int maxn=(1e6)+10;
int n,m;
vector<char> s[maxn];
char t[maxn];
int b[maxn],q;
int main() {
	read(n),read(m);
	for (int i=0;i<=n+2;i++) s[i].resize(m+2);
	for (int i=1;i<=n;i++) {
		scanf("%s",t+1);
		for (int j=1;j<=m;j++) s[i][j]=t[j];
	}
	for (int i=2;i<=m;i++) for (int j=2;j<=n;j++) {
		if (s[j][i-1]=='X'&&s[j-1][i]=='X') { b[i]=1; break; }
	}
	for (int i=2;i<=m;i++) b[i]+=b[i-1]; read(q); int l,r;
	while (q--) {
		read(l),read(r);
		if (r==l) puts("YES");
		else if (b[r]-b[l]==0) puts("YES");
		else puts("NO");
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