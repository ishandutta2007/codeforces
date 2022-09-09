#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=105;
ll dp[N][N][N],a[N];
bool was[N][N][N];
char s[N];
ll DP(int l, int r, int f)
{
	if(was[l][r][f]) return dp[l][r][f];
	if(l>r) return 0;
	was[l][r][f]=1;
	dp[l][r][f]=DP(l+1,r,0)+a[f+1];
	for(int i=l+1;i<=r;i++) if(s[i]==s[l]) dp[l][r][f]=max(dp[l][r][f],DP(l+1,i-1,0)+DP(i,r,f+1));
	return dp[l][r][f];
}
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	printf("%lld\n",DP(1,n,0));
	return 0;
}