#include <bits/stdc++.h>
using namespace std;
int dp[4000005],qzh[4000005],d[4000005],f[1005],cnt;
vector <int> p,k;
inline void dfs(int now,int x)
{
	if(now==p.size())
	{
		f[++cnt]=x;
		return ;
	}
	for(int i=0;i<=k[now];i++)
		dfs(now+1,x),x*=p[now];
}
signed main()
{
	int n,mod;
	cin >> n >> mod;
	f[1]=qzh[1]=dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=qzh[i-1];
		++d[i];
		d[i]+=d[i-1],d[i]%=mod;
		cnt=0,p.clear(),k.clear();
		int x=i;
		for(int j=2;j*j<=x;j++)
		{
			if(x%j==0)
			{
				int qwq=0;
				while(x%j==0)x/=j,++qwq;
				p.push_back(j),k.push_back(qwq);
			}
		}
		if(x>1) p.push_back(x),k.push_back(1);
		dfs(0,1);
		for(int j=1;j<=cnt;j++)
			if(f[j]>1&&f[j]!=i)d[i]+=dp[f[j]]-dp[f[j]-1],d[i]%=mod;
		dp[i]=(dp[i]+mod)%mod;
		d[i]=(d[i]+mod)%mod;
		dp[i]+=d[i],dp[i]%=mod;
		qzh[i]=(qzh[i-1]+dp[i])%mod;
	}
	cout << (dp[n]+mod)%mod;
	return 0;
}
/*
4000000 123456789
*/