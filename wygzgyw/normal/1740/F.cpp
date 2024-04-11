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
const int mod=998244353;
const int maxn=2010;
int n,cnt[maxn];
int dp[maxn][maxn];
int S[maxn];
void update(int &x,int y) { x+=y; if (x>=mod) x-=mod; }
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int x; read(x); cnt[x]++;
	}
	for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) S[i]+=min(i,cnt[j]);
	dp[0][0]=1;
	for (int i=n;i>=1;i--) {
		for (int j=0;j<n;j++) for (int sum=j*i;sum<=n-i;sum++) if (dp[j][sum]) {
			int pre=sum+i;
			if (S[j+1]>=pre) update(dp[j+1][sum+i],dp[j][sum]);
		}
	}
	int ans=0;
	for (int i=1;i<=n;i++) update(ans,dp[i][n]);
	printf("%d\n",ans);
	return 0;
}