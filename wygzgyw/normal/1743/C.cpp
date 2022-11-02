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
const ll INF=1e18;
const int maxn=(3e5)+10;
int T,n;
ll dp[maxn][2],a[maxn];
char s[maxn];
void chkmax(ll &x,ll y) { if (x<y) x=y; }
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1);
		for (int i=1;i<=n;i++) read(a[i]);
		dp[1][0]=(s[1]=='1'?a[1]:0);
		dp[1][1]=(s[2]!='1'?-INF:a[1]);
		for (int i=1;i<n;i++) {
			dp[i+1][0]=dp[i+1][1]=-INF;
			for (int j=0;j<=1;j++) {
				for (int v=0;v<=1;v++) {
					int tmp;
					if (!v) tmp=(j==0&&s[i+1]=='1');
					else {
						tmp=1;
						if (s[i+2]!='1') continue;
					}
					chkmax(dp[i+1][v],dp[i][j]+tmp*a[i+1]);
				}
			}
		}
		printf("%lld\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}