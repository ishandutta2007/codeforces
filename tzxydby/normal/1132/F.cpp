#include<bits/stdc++.h>
using namespace std;
const int N=505;
int dp[N][N],n;
char s[N];
int dfs(int l,int r)
{
	if(l>r) return 0;
	int &f=dp[l][r];
	if(f!=-1) return f;
	f=dfs(l+1,r);
	for(int i=l+1;i<=r;i++)
		if(s[l]==s[i])
			f=max(f,1+dfs(l+1,i-1)+dfs(i,r));
	return f; 
}
int main()
{
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=-1;
	printf("%d\n",n-dfs(1,n));
	return 0;
}