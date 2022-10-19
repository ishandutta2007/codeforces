#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
long long dp[N][N],a[N],n,m;
long long dfs(int l,int r)
{
	if(dp[l][r])
		return dp[l][r];
	if(l>=r)
		return dp[l][r]=1;
	int p=l;
	for(int i=l;i<=r;i++)
		if(a[i]<a[p])
			p=i;
	long long s1=0,s2=0;
	for(int i=l;i<=p;i++)
		s1=(s1+dfs(l,i-1)*dfs(i,p-1)%mod)%mod;
	for(int j=p;j<=r;j++)
		s2=(s2+dfs(p+1,j)*dfs(j+1,r)%mod)%mod;
	return dp[l][r]=s1*s2%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<dfs(1,n)<<endl;
	return 0;
}