#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int INF=0x7f7f7f7f;
const int maxn=(1e5)+10;
int T,dp[maxn][2][2];
int n;
char s[maxn];
void update(int &x,int y) { if (x>y) x=y; }
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		scanf("%s",s+1);
		n=strlen(s+1);
		for (int i=0;i<=n;i++)
		for (int j=0;j<=1;j++) for (int k=0;k<=1;k++) dp[i][j][k]=INF;
		dp[0][0][0]=0;
		// j k op
		int ans=INF;
		for (int i=0;i<=n;i++)
		for (int j=0;j<=1;j++)
		for (int k=0;k<=1;k++) if (dp[i][j][k]<INF) {
			if (i==n) update(ans,dp[i][j][k]);
			for (int op=0;op<=1;op++) {
				if (i>1&&i<n&&!j&&!op&&s[i+1]==s[i-1]) continue;
				if (i>0&&i<n&&!k&&!op&&s[i+1]==s[i]) continue;
				update(dp[i+1][k][op],dp[i][j][k]+op);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/