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
const int INF=1e9;
const int maxn=(2e5)+10;
int T;
int n;
char s[maxn],t[maxn];
int dp[maxn][4][3];
int main() {
	read(T);
	while (T--) {
		read(n);
		scanf("%s",s+1),scanf("%s",t+1);
		for (int i=0;i<=n;i++) for (int j=0;j<4;j++) for (int v=0;v<3;v++) dp[i][j][v]=INF;
		dp[0][0][0]=0;
		for (int i=1;i<=n;i++) for (int j=0;j<4;j++) for (int v=0;v<3;v++) {
			for (int k=0;k<4;k++) {
				if (s[i]=='*'&&k%2==0) continue;
				if (t[i]=='*'&&(k&2)==0) continue;
				if (j==1&&k==2) continue;
				if (j==2&&k==1) continue;
				int v2=v;
				if (k&&v2==2) continue;
				if (k&&v2==0) v2=1;
				if (!k&&v2==1) v2=2;
				dp[i][k][v2]=min(dp[i-1][j][v]+__builtin_popcount(k),dp[i][k][v2]);
			}
		}
		int ans=INF;
		for (int v=0;v<3;v++)
		for (int k=0;k<4;k++) ans=min(ans,dp[n][k][v]); printf("%d\n",ans-1);
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