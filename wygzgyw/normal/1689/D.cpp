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
const int INF=1e9;
const int maxn=1010;
int T,n,m;
void chkmax(int &x,int y) { if (x<y) x=y; }
char s[maxn];
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		int A=-INF,B=-INF,C=-INF,D=-INF;
		for (int i=1;i<=n;i++) {
			scanf("%s",s+1);
			for (int j=1;j<=m;j++) if (s[j]=='B') {
				chkmax(A,-i-j);
				chkmax(B,i-j);
				chkmax(C,j-i);
				chkmax(D,i+j);
			}
		}
		int res=INF,X,Y;
		for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) {
			int tmp=0;
			chkmax(tmp,i+j+A);
			chkmax(tmp,-i+j+B);
			chkmax(tmp,i-j+C);
			chkmax(tmp,-i-j+D);
			if (tmp<res) res=tmp,X=i,Y=j;
		}
		printf("%d %d\n",X,Y);
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