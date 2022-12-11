#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
	return b?gcd(b,a%b):a;
}
int R;
const int max_R=3e5+5;
bool mark_p[max_R];
int prime[max_R],t,pf[max_R];
inline void init()
{
	for(int i=2;i<=R;++i)
		mark_p[i]=true;
	for(int i=2;i<=R;++i)
	{
		if(mark_p[i])
		{
			prime[++t]=i;
			pf[i]=i;
		}
		for(int j=1;j<=t&&i*prime[j]<=R;++j)
		{
			mark_p[i*prime[j]]=false;
			pf[i*prime[j]]=prime[j];
			if(i%prime[j]==0)
				break;
		}
	}
}
const int max_n=3e5+5;
int a[max_n];
vector<int> Prime[max_n];
const int max_s=1<<6|5;
int Log[max_s],cnt[max_s],dp[max_s];
bool mark[max_s];
vector<int> val[max_n];
int tot[max_R];
int main()
{
	int n,d=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		R=max(R,a[i]);
		d=gcd(d,a[i]);
	}
	if(d>1)
	{
		puts("-1");
		return 0;
	}
	init();
	Log[0]=-1;
	for(int s=1;s<64;++s)
		Log[s]=Log[s>>1]+1;
	for(int i=1;i<=n;++i)
	{
		int t=a[i];
		while(t>1)
		{
			int p=pf[t];
			Prime[i].push_back(p);
			while(t%p==0)
				t/=p;
		}
		int sz=Prime[i].size();
		assert(sz<=6);
		val[i].resize(1<<sz);
		val[i][0]=1,++tot[1];
		for(int s=1;s<int(val[i].size());++s)
		{
			val[i][s]=val[i][s^(1<<Log[s])]*Prime[i][Log[s]];
			++tot[val[i][s]];
		}
	}
	int ans=7;
	for(int i=1;i<=n;++i)
	{
		int Full=(1<<Prime[i].size())-1;
		for(int s=Full;s>=0;--s)
		{
			cnt[s]=tot[val[i][s]];
			int u=s^Full;
			for(int t=u;t;t=(t-1)&u)
				cnt[s]-=cnt[s^t];
			mark[s]=false;
		}
		for(int s=0;s<=Full;++s)
		{
			if(cnt[s^Full]>0)
			{
				for(int t=s;t;t=(t-1)&s)
					mark[t]=true;
			}
		}
		dp[0]=1;
		for(int s=1;s<=Full;++s)
		{
			dp[s]=1e9;
			for(int t=s;t;t=(t-1)&s)
			{
				if(mark[t])
					dp[s]=min(dp[s],dp[s^t]+1);
			}
		}
		assert(dp[Full]!=1e9);
		ans=min(ans,dp[Full]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
3
30 3 5
*/