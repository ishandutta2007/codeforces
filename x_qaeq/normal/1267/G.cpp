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
int n,sm,c[105];double X,dp[105][10005],rs=0;
int main()
{
	read(n),scanf("%lf",&X),X/=2,sm=0,dp[0][0]=1;
	for(int i=1;i<=n;i++) read(c[i]),sm+=c[i];
	for(int i=1;i<=n;i++) for(int k=i;k;k--) for(int j=sm;j>=c[i];j--)
		dp[k][j]+=dp[k-1][j-c[i]]/(n-k+1)*k;
	for(int k=1;k<=n;k++) for(int j=0;j<=sm;j++) rs+=dp[k][j]*min((1.0*n/k+1)*X,1.0*j/k);
	return printf("%.10lf\n",rs),0;
}