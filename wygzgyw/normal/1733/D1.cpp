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
const ll INF=1e18;
char s[maxn],t[maxn];
int T,n;
int d[maxn];
ll dp[2][maxn][2][2],x,y;
void chkmin(ll &x,ll y) { if (x>y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n); read(x),read(y);
		scanf("%s",s+1);
		scanf("%s",t+1);
		int cnt=0;
		for (int i=1;i<=n;i++) d[i]=(s[i]!=t[i]),cnt+=d[i];
		if (cnt%2==1) { puts("-1"); continue; }
		for (int j=0;j<=n;j++) for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) dp[0][j][a][b]=INF;
		dp[0][0][0][0]=0;
		for (int i=0;i<n;i++) {
			for (int j=0;j<=n;j++) for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) dp[i&1^1][j][a][b]=INF;
			
			for (int j=2;j<=n;j++) {
				for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) if (dp[i&1][j-2][a][b]!=INF) chkmin(dp[i&1][j][a][b],dp[i&1][j-2][a][b]);
			}
			for (int j=n;j>=2;j--) {
				for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) if (dp[i&1][j][a][b]!=INF) chkmin(dp[i&1][j-2][a][b],dp[i&1][j][a][b]+2*y);
			}
			for (int j=0;j<=n;j++) {
				for (int a=0;a<=1;a++) for (int b=0;b<=1;b++) if (dp[i&1][j][a][b]!=INF) {
					for (int v=0;v<=1;v++) {
						if (i==0&&v) continue;
						for (int j2=0;j2<=j+a&&j2<=1;j2++) {
							chkmin(dp[i&1^1][j-j2+a][b^v][v^(j2&1)^d[i+1]],dp[i&1][j][a][b]+v*x+j2*y);
						}
					}
				}
			}
		}
		printf("%lld\n",dp[n&1][0][0][0]);
	}
	return 0;
}