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
int T,n,m;
char s[60][60],t[60][60];
bool check() {
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++)
		if (s[i][j]!='.'&&s[i][j]!=t[i][j]) return 0;
	return 1;
}
void print() { puts("YES");
	for (int i=1;i<=n;i++) { for (int j=1;j<=m;j++) printf("%c",t[i][j]); puts(""); }
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if ((i+j)&1) t[i][j]='R'; else t[i][j]='W';
		if (check()) { print(); continue; }
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) if ((i+j)&1) t[i][j]='W'; else t[i][j]='R';
		if (check()) { print(); continue; }
		puts("NO");
		
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