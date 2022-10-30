#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
const int P=1e9+7;
int Ca,n,m,dp[1005][1005],s[1005][1005];
inline void solve()
{
	read(n),read(m);for(int i=0;i<=n;i++) dp[1][i+1]=1,s[1][i+1]=s[1][i]+1;
	for(int i=2;i<=m;i++)
	{
		for(int j=0;j<=n;j++) dp[i][j+1]=(1+s[i-1][n]-s[i-1][n-j])%P;
		for(int j=0;j<=n;j++) s[i][j+1]=(s[i][j]+dp[i][j+1])%P;
	}
	printf("%d\n",(dp[m][n+1]+P)%P);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}