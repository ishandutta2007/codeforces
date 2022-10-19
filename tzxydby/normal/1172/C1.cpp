#include<bits/stdc++.h>
#define pii pair<int,int>
#define se second
#define mp make_pair
#define mod 998244353
#define N 55
#define int long long
using namespace std;
long long qp(long long a,long long b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}	
	return ans;
} 
inline int add(int a,int b)
{
	int c=a+b;
	if(c>=mod)
		c-=mod;
	return c;
}
inline int mul(int a,int b)
{
	long long c=a*b%mod;
	return c; 
}
inline int inv(int a,int b)
{
	long long c=a*qp(b,mod-2)%mod;
	return c;
}
map<pair<pii,pii>,int>dp;
int n,m,s0,s1,a[N],b[N];
int dfs(int i,int j,int k,int l,int id) 
{
	if(i==m)
		return j;
	auto x=mp(mp(i,j),mp(k,l));
	if(dp.find(x)!=dp.end())
		return dp[x];
	dp[x]=0;
	if(a[id])
	{
		dp[x]=add(dp[x],mul(inv(j,k+l),dfs(i+1,j+1,k+1,l,id)));
		if(k-j) dp[x]=add(dp[x],mul(inv(k-j,k+l),dfs(i+1,j,k+1,l,id)));
		if(l) dp[x]=add(dp[x],mul(inv(l,k+l),dfs(i+1,j,k,l-1,id)));
	}
	else
	{	
		if(j) dp[x]=add(dp[x],mul(inv(j,k+l),dfs(i+1,j-1,k,l-1,id)));
		dp[x]=add(dp[x],mul(inv(k,k+l),dfs(i+1,j,k+1,l,id)));
		if(l-j) dp[x]=add(dp[x],mul(inv(l-j,k+l),dfs(i+1,j,k,l-1,id)));
	}
	return dp[x];
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&b[i]);
		if(!a[i])
			s0+=b[i];
		else
			s1+=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp.clear();
		printf("%d\n",dfs(0,b[i],s1,s0,i));
	}
	return 0;
}