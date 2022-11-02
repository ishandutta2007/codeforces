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
int T,n,a[60][60],p[120];
char s[10]; int x;
vector<int> E[60];
int I;
bool cmp(int x,int y) { return a[I][x-n]<a[I][y-n]; }
int main() {
	read(T); while (T--) {
		read(n);
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) read(a[i][j]);
		puts("B"); fflush(stdout);
		scanf("%s",s+1); read(x);
		if ((s[1]=='D')^(x>n)) { for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) a[i][j]*=-1; }
		memset(p,0,sizeof(p));
		for (int i=1;i<=n;i++) {
			E[i].clear(); I=i;
			for (int j=1;j<=n;j++) E[i].push_back(j+n);
			sort(E[i].begin(),E[i].end(),cmp);
		}
		int cnt=n;
		while (cnt) {
			for (int i=1;i<=n;i++) if (!p[i]) {
				for (int &j : E[i]) {
					if (!p[j]) { p[j]=i,p[i]=j; cnt--; break; }
					if (a[i][j-n]>a[p[j]][j-n]) { p[p[j]]=0,p[i]=j,p[j]=i; break; }
				}
			}
		}
		while (1) {
			printf("%d\n",p[x]); fflush(stdout);
			read(x); if (x<0) break;
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