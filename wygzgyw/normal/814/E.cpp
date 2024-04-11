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
const int maxn=60;
int n,deg[maxn],f[maxn][maxn],g[maxn][maxn][maxn];
int N[maxn],C[maxn][maxn],ans;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(deg[i]);
	for (int i=0;i<=n;i++) {
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	N[2]=N[3]=1; for (int i=4;i<=n;i++) N[i]=(ll)N[i-1]*(i-1)%mod;
	g[0][0][0]=1;
	for (int k=1;k<=n;k++) for (int l=3;l<=k;l++)
		update(g[0][0][k],(ll)g[0][0][k-l]*C[k-1][l-1]%mod*N[l]%mod);
	for (int j=1;j<=n;j++) for (int k=0;k+j<=n;k++) {
		if (j>=2) update(g[0][j][k],(ll)g[0][j-2][k]*(j-1)%mod);
		if (k>=1) update(g[0][j][k],(ll)g[0][j][k-1]*k%mod);
	}
	for (int i=1;i<=n;i++) for (int j=0;i+j<=n;j++) for (int k=0;i+j+k<=n;k++) {
		if (j) update(g[i][j][k],(ll)g[i-1][j-1][k]*j%mod);
		if (k) update(g[i][j][k],(ll)g[i-1][j+1][k-1]*k%mod);
	}
	f[deg[1]+1][deg[1]]=1;
	for (int i=deg[1]+1;i<=n;i++) for (int j=1;j<=i;j++) {
		int c2=0,c3=0;
		for (int k=1;k<=i-j+1;k++) {
			if (deg[i-j-k+1]==2) c2++; else c3++;
			update(f[i][j],(ll)f[i-j][k]*g[j][c2][c3]%mod);
		}
	}
	int c2=0,c3=0;
	for (int i=1;i<n;i++) {
		if (deg[n-i+1]==2) c2++; else c3++;
		update(ans,(ll)f[n][i]*g[0][c2][c3]%mod);
	}
	printf("%d\n",ans);
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