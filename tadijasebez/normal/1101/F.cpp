#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=405;
const int inf=1e9+7;
int dp[N][N][N],a[N];
int DP(int l, int r, int c)
{
	if(l==r) return 0;
	if(l+1==r) return a[r]-a[l];
	if(dp[l][r][c]) return dp[l][r][c];
	if(c==0) return dp[l][r][c]=a[r]-a[l];
	int opt=(a[r]-a[l])/(c+1);
	int i=lower_bound(a+l,a+r+1,a[l]+opt)-a;
	dp[l][r][c]=inf;
	if(i!=l) dp[l][r][c]=min(dp[l][r][c],max(DP(i-1,r,c-1),a[i-1]-a[l]));
	dp[l][r][c]=min(dp[l][r][c],max(DP(i,r,c-1),a[i]-a[l]));
	if(i!=r) dp[l][r][c]=min(dp[l][r][c],max(DP(i+1,r,c-1),a[i+1]-a[l]));
	return dp[l][r][c];
}
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
    ll ans=0;
    int l,r,mul,c;
    while(m--)
	{
		scanf("%i %i %i %i",&l,&r,&mul,&c);
		c=min(c,r-l);
		ans=max(ans,(ll)DP(l,r,c)*mul);
	}
	printf("%lld\n",ans);
	return 0;
}