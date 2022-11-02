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
bool a[30][30],b[30][30]; int now,p[10];
void insert(int x,int y) {
	if (a[x-1][y]||a[x][y-1]||a[x+1][y]||a[x][y+1]||a[x-1][y-1]||a[x+1][y+1]||a[x-1][y+1]||a[x+1][y-1]) return;
	a[x][y]=1; now++;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n),read(m);
		int ans=0; memset(b,0,sizeof(b)), memset(a,0,sizeof(a));
		for (int t=0;t<4;t++) {
			for (int i=1;i<=4;i++) p[i]=i;
			do {
				for (int i=1;i<=n;i++) a[i][1]=a[i][m]=0;
				for (int i=1;i<=m;i++) a[1][i]=a[n][i]=0;
				now=0;
				for (int I=1;I<=4;I++) {
					int i=p[I];
					if (i==1) {
						for (int j=1;j<=m;j+=2) insert(1,j);
					} else if (i==2) {
						for (int j=1;j<=n;j+=2) insert(j,1);
					} else if (i==3) {
						for (int j=2-(t&1);j<=m;j+=2) insert(n,j);
					} else {
						for (int j=2-(t>>1&1);j<=n;j+=2) insert(j,m);
					}
				}
				if (ans<now) {
					ans=now;
					for (int i=1;i<=n;i++) b[i][1]=a[i][1],b[i][m]=a[i][m];
					for (int i=1;i<=m;i++) b[1][i]=a[1][i],b[n][i]=a[n][i];
				}
			} while (next_permutation(p+2,p+5));
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++) printf("%d",b[i][j]); puts("");
		}
		puts("");
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