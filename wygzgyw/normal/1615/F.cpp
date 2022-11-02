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
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=4010;
int T,n,f[maxn/2][maxn],g[maxn/2][maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
char s[maxn],t[maxn];
int main() {
	read(T); while (T--) {
		read(n);
		scanf("%s",s+1); scanf("%s",t+1);
		for (int i=1;i<=n;i+=2) {
			if (s[i]!='?') s[i]^=1;
			if (t[i]!='?') t[i]^=1;
		}
		//printf("%s\n",s+1);
		//printf("%s\n",t+1);
		for (int i=0;i<=n;i++) for (int j=-n;j<=n;j++) f[i][j+n]=g[i][j+n]=0;
		f[0][n]=1;
		for (int i=0;i<n;i++) {
			for (int x=0;x<=1;x++) for (int y=0;y<=1;y++) {
				if (s[i+1]!='?'&&s[i+1]-'0'!=x) continue;
				if (t[i+1]!='?'&&t[i+1]-'0'!=y) continue;
				int delta; if (x==y) delta=0; else if (x==1) delta=1; else delta=-1;
				for (int j=-i;j<=i;j++) {
					update(f[i+1][j+delta+n],f[i][j+n]);
					update(g[i+1][j+delta+n],g[i][j+n]);
					if (delta==0) continue;
					if (x==1) {
						if (j+1>0) {
					//		printf("%d\n",-(i+1));
							update(g[i+1][j+delta+n],(ll)f[i][j+n]*(mod-(i+1))%mod);
						} else update(g[i+1][j+delta+n],(ll)f[i][j+n]*(i+1)%mod);
					}
					if (y==1) {
						if (j-1>=0) {
						//	printf("%d\n",i+1);
							update(g[i+1][j+delta+n],(ll)f[i][j+n]*(i+1)%mod);
						}
						else update(g[i+1][j+delta+n],(ll)f[i][j+n]*(mod-(i+1))%mod);
					}
				}
			}
		}
		printf("%d\n",g[n][n]);
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