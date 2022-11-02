#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int T,n,m;
char ans[510][510];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) {
			scanf("%s",ans[i]+1);
		}
		if (n==1) {
			for (int i=1;i<=m;i++) putchar('X'); puts("");
			continue;
		}
		if (m==1) {
			for (int i=1;i<=n;i++) puts("X");
			continue;
		}
		for (int i=1;i<=n;i+=3) {
			for (int j=1;j<=m;j++) ans[i][j]='X';
		}
		for (int i=1;i+3<=n;i+=3) {
			int pos=1;
			for (int j=1;j<=m;j++) {
				if (ans[i+1][j]=='X'||ans[i+2][j]=='X') { pos=j; break; }
			}
			ans[i+1][pos]=ans[i+2][pos]='X';
		}
		if (n%3==0) {
			for (int i=1;i<=m;i++) {
				if (ans[n][i]=='X') ans[n-1][i]='X';
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) printf("%c",ans[i][j]);
			puts("");
		}
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