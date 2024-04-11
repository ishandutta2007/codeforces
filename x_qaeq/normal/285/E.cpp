//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n,m,dp[1005][1005][2][2],fc[1005],fi[1005],F[1005],G[1005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline int pl(int a,int b) {return (a+=b)>=P?a-=P:a;}
int main()
{
	read(n),read(m),fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[n]=ksm(fc[n]);for(int i=n;i;i--) fi[i-1]=1ll*fi[i]*i%P;
	dp[1][0][0][0]=1,dp[1][1][0][1]=1;
	for(int i=2;i<n;i++)
	{
		dp[i][0][0][0]=1;for(int j=1;j<=i;j++)
		{
			dp[i][j][0][0]=pl(pl(dp[i-1][j-1][0][0],dp[i-1][j][0][0]),dp[i-1][j][1][0]);
			dp[i][j][1][0]=pl(pl(dp[i-1][j-1][0][1],dp[i-1][j][0][1]),dp[i-1][j][1][1]);
			dp[i][j][0][1]=pl(dp[i-1][j-1][0][0],dp[i-1][j-1][1][0]);
			dp[i][j][1][1]=pl(dp[i-1][j-1][0][1],dp[i-1][j-1][1][1]);
			//printf("%d %d %d %d\n",dp[i][j][0][0],dp[i][j][0][1],dp[i][j][1][0],dp[i][j][1][1]);
		}
	}
	dp[n][0][0][0]=1;for(int j=1;j<=n;j++)
	{
		dp[n][j][0][0]=pl(pl(dp[n-1][j-1][0][0],dp[n-1][j][0][0]),dp[n-1][j][1][0]);
		dp[n][j][1][0]=pl(pl(dp[n-1][j-1][0][1],dp[n-1][j][0][1]),dp[n-1][j][1][1]);
	}
	for(int i=0;i<=n;i++) F[i]=1ll*(dp[n][i][0][0]+dp[n][i][1][0])*fc[n-i]%P;
	int rs=0;for(int i=m;i<=n;i++) rs=(rs+1ll*((i-m)&1?P-1ll:1ll)*C(i,m)%P*F[i])%P;
	return printf("%d\n",rs),0;
}