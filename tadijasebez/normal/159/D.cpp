#include <stdio.h>
#include <cstring>
#define ll long long
const int N=2005;
bool dp[N][N],was[N][N];
char s[N];
bool DP(int l, int r)
{
	if(l>r) return 1;
	if(was[l][r]) return dp[l][r];
	was[l][r]=1;
	if(s[l]==s[r] && DP(l+1,r-1)) dp[l][r]=1;
	return dp[l][r];
}
int L[N],R[N];
int main()
{
	int n,i,j;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(i=1;i<=n;i++) for(j=i;j<=n;j++) L[j]+=DP(i,j),R[i]+=DP(i,j);
	ll sol=0;
	for(i=2;i<=n;i++)
	{
		sol+=(ll)R[i]*L[i-1];
		L[i]+=L[i-1];
	}
	printf("%lld\n",sol);
	return 0;
}