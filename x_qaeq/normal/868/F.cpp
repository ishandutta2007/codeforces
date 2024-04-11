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
int n,K,L,R,a[100005],cn[100005];ll nw,dp[21][100005];
inline void move(int l,int r)
{
	while(L<l) nw-=--cn[a[L++]];
	while(R<r) nw+=cn[a[++R]]++;
	while(L>l) nw+=cn[a[--L]]++;
	while(R>r) nw-=--cn[a[R--]];
}
inline void solve(int l,int r,int dl,int dr,int wh)
{
	int md=(l+r)>>1,dmd;if(l>r) return;
	for(int i=dl;i<=min(md,dr);i++)
	{
		move(i,md);ll vl=dp[wh-1][i-1]+nw;
		if(vl<dp[wh][md]) dp[wh][md]=vl,dmd=i;
	}
	solve(l,md-1,dl,dmd,wh),solve(md+1,r,dmd,dr,wh);
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	memset(dp,0x3f,sizeof(dp)),dp[0][0]=0,L=1,R=0;
	for(int i=1;i<=K;i++) solve(1,n,1,n,i);
	return printf("%lld\n",dp[K][n]),0;
}