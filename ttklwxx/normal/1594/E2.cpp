#include<iostream>
#include<cstdio>
#include<map>
#define int long long
#define mod 1000000007
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int dp[100005];
int ksm(int n,int k)
{
	int ans=1;
	while(k>=1)
	{
		if(k&1)ans=1LL*ans*n%mod;
		k>>=1;
		n=1LL*n*n%mod;
	}
	return ans;
}
map<int,int>col,siz,tans[3];
int k;
void dfs(int dep,int sth)
{
	//printf("vis:%d\n",sth);
	if(siz[sth]==0)
	{
		tans[0][sth]=tans[1][sth]=tans[2][sth]=dp[k-dep];
		return;
	}
	if(dep==k-1)
	{
		if(col[sth]==1)tans[0][sth]=1;
		else if(col[sth]==2)tans[1][sth]=1;
		else if(col[sth]==3)tans[2][sth]=1;
		return;
	}
	dfs(dep+1,sth*2);
	dfs(dep+1,sth*2+1);
	if(col[sth]==1||col[sth]==0)tans[0][sth]=(tans[1][sth*2]+tans[2][sth*2])*(tans[1][sth*2+1]+tans[2][sth*2+1])%mod;
	if(col[sth]==2||col[sth]==0)tans[1][sth]=(tans[0][sth*2]+tans[2][sth*2])*(tans[0][sth*2+1]+tans[2][sth*2+1])%mod;
	if(col[sth]==3||col[sth]==0)tans[2][sth]=(tans[0][sth*2]+tans[1][sth*2])*(tans[0][sth*2+1]+tans[1][sth*2+1])%mod;
	//printf("%lld %lld %lld %lld\n",sth,tans[0][sth],tans[1][sth],tans[2][sth]);
}
char str[105];
signed main()
{
	int n,x;
	k=read();
	n=read();
	dp[1]=1;
	for(int i=2;i<=k;i++)dp[i]=4LL*dp[i-1]%mod*dp[i-1]%mod;
	for(int i=1;i<=n;i++)
	{
		x=read();
		scanf("%s",str+1);
		if(str[1]=='w')col[x]=1;
		else if(str[1]=='y')col[x]=1;
		else if(str[1]=='g')col[x]=2;
		else if(str[1]=='b')col[x]=2;
		else if(str[1]=='r')col[x]=3;
		else if(str[1]=='o')col[x]=3;
		while(x!=0)
		{
			siz[x]=1;
			x/=2;
		}
	}
	dfs(0,1);
	printf("%lld\n",(tans[0][1]+tans[1][1]+tans[2][1])%mod*ksm(2,(1LL<<k)-1-n)%mod);
	return 0;
}