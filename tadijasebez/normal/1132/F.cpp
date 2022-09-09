#include <bits/stdc++.h>
using namespace std;
const int N=550;
char s[N];
int dp[N][N];
bool was[N][N];
int Solve(int l, int r)
{
	if(l==r) return 1;
	if(l>r) return 0;
	if(was[l][r]) return dp[l][r];
	was[l][r]=1;
	dp[l][r]=Solve(l+1,r)+1;
	for(int i=l+1;i<=r;i++) if(s[i]==s[l]) dp[l][r]=min(dp[l][r],Solve(l+1,i-1)+Solve(i,r));
	return dp[l][r];
}
int main()
{
	int n,i;
	scanf("%i",&n);
	scanf("%s",s+1);
	n=unique(s+1,s+1+n)-s-1;
	printf("%i\n",Solve(1,n));
	return 0;
}