#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
int n,m;
int dp[12][1010][1010];
ll s[12][1010][1010],ans;
int main() {
	//freopen("1.txt","r",stdin);
	//printf("MLE %d\n",(sizeof(dp)+sizeof(s))/1024/1024);
	read(n); read(m);
	dp[0][0][0]=1;
	for (int i=0;i<=n;i++)
	for (int j=0;j<=n;j++) s[0][i][j]=1;
	for (int i=1;i<=m;i++) {
		for (int j=1;j<=n;j++)
		for (int k=j;k<=n;k++) {
			dp[i][j][k]=s[i-1][j][k];
			if (i==m) {
				ans+=dp[i][j][k];
				if (ans>=mod) ans-=mod;
			}
		}
		for (int j=1;j<=n;j++)
		for (int k=n;k>=1;k--) {
			s[i][j][k]=s[i][j-1][k]+s[i][j][k+1]-s[i][j-1][k+1]+dp[i][j][k];
			s[i][j][k]%=mod;
		}
	}
	printf("%lld\n",ans);
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