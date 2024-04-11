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
const int maxn=(5e5)+10;
int n,ans[maxn],b[maxn],c[maxn],d[maxn];
bool chk(int x,int y) { return (x&y)==0; }
int dp[1010][1010];
int main() {
	read(n);
	for (int i=0;i<n;i++) read(b[i]);
	int msk=1; while (msk<=n) msk*=2;
	for (int i=1;i<msk;i<<=1) for (int j=0;j<n;j++) if (j&i) b[j]^=b[j^i];
	for (int i=1;i<msk;i<<=1) for (int j=0;j<n;j++) if (j&i) b[j^i]^=b[j];
	
	for (int i=1;i<=n;i++) ans[i]=b[n-i];
	for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	return 0;
	for (int i=1;i<=n;i++) dp[0][i]=ans[i];
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) dp[i][j]=dp[i-1][j]^dp[i][j-1];
	}
	for (int i=1;i<=n;i++) printf("%d ",dp[i][n]); puts("");
	return 0;
}