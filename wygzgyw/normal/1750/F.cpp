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
const int maxn=5010;
int n,mod;
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int f[maxn],mi[maxn];
int dp[maxn][maxn];
int s[maxn],s2[maxn];
int main() {
	read(n),read(mod);
	dp[1][1]=f[1]=1;
	mi[0]=1; for (int i=1;i<=n;i++) mi[i]=mi[i-1]*2%mod;
	for (int i=1;i<=n;i++) {
		if (i>1) f[i]=mi[i-2];
		for (int j=1;j<=n;j++) s2[j]=(s2[j-1]+s[j])%mod;
		for (int j=1;j<i;j++) {
			if (i-j*2-1>=0) update(dp[i][j],(ll)f[j]*s2[i-j*2-1]%mod);
//			for (int v=1;v<=i-j*2-1;v++) for (int v2=1;v2<=v;v2++) if (v+v2<=i-j*2-1) update(dp[i][j],(ll)f[j]*dp[v][v2]%mod);
			update(f[i],mod-dp[i][j]);
		}
		dp[i][i]=f[i];
		for (int j=1;j<=i&&i+j<=n;j++) update(s[i+j],dp[i][j]);
	}
	printf("%d\n",f[n]);
	return 0;
}