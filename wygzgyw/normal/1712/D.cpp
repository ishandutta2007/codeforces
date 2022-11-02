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
const int maxn=(1e5)+10;
int T,n,dp[maxn][2][2],a[maxn],k;
bool solve(int mid) {
	dp[1][0][0]=0;
	dp[1][1][0]=1;
	if (2*a[1]<mid) dp[1][0][0]=1e9;
	dp[1][0][1]=dp[1][1][1]=1e9;
	for (int i=2;i<=n;i++) {
		for (int j=0;j<2;j++) for (int k=0;k<2;k++)
			dp[i][j][k]=1e9;
		for (int j=0;j<2;j++) for (int pre=0;pre<2;pre++) for (int k=0;k<2;k++) {
			if (2*a[i]<mid&&!k) continue;
			int nxt=pre;
			int x=(j?1e9:a[i-1]),y=(k?1e9:a[i]);
			if (min(x,y)>=mid) nxt=1;
			dp[i][k][nxt]=min(dp[i][k][nxt],dp[i-1][j][pre]+k);
		}
	}
	return min(dp[n][0][1],dp[n][1][1])<=k;
}
int main() {
	read(T);
	while (T--) {
		read(n); read(k);
		for (int i=1;i<=n;i++) read(a[i]);
		if (n==k) { puts("1000000000"); continue; }
		int l=1,r=1e9,mid,res=-1;
		while (l<=r) {
			mid=(l+r)>>1;
			if (solve(mid)) res=mid,l=mid+1; else r=mid-1;
		}
		printf("%d\n",res);
	}
	return 0;
}