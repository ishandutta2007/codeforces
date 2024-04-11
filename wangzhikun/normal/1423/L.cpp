#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
bitset<1000>bt,bas[1005];
int n,q,s,k,cnt1=0,basstr[1005],cnt2=0,str[1005],x,alm;
int dp[32768],dp2[32768],dp3[32768];
void solve1()
{
	int res=s-cnt1;
	int x,cnt=0;
	for(int i=0;i<(1<<(res-res/2));i++)
	{
		x=0;cnt=0;
		for(int j=0;j<res-res/2;j++)if((1<<j)&i)x^=str[j+res/2],cnt++;
		dp2[x]=min(dp2[x],cnt);
	}
	for(int i=0;i<32768;i++)dp3[i]=10000;
	dp3[0]=0;
	for(int i=0;i<32768;i++)for(int j=i;j;j=(j-1)&i)dp3[j]=min(dp3[j],__builtin_popcount(i-j)+dp2[i]);
	dp2[0]=0;
	for(int i=1;i<32768;i++)dp2[i]=10000;
	for(int i=1;i<32768;i++)
	{
		for(int j=i;j;j=(j-1)&i)dp2[i]=min(dp2[i],__builtin_popcount(i-j)+dp3[j]);
		dp2[i]=min(dp2[i],__builtin_popcount(i));
	}
	for(int i=0;i<(1<<cnt1);i++)
	{
		for(int j=0;j<(1<<(res/2));j++)
		{
			x=cnt=0;
			for(int k=0;k<res/2;k++)if((1<<k)&j)x^=str[k],cnt++;
			dp[i]=min(dp[i],cnt+dp2[i^x]);
		}
	}
}
void solve2()
{
	int x;
	for(int i=0;i<(1<<cnt2);i++)
	{
		x=0;
		for(int j=0;j<cnt2;j++)if((1<<j)&i)x^=str[j];
		dp[i]=x;
	}
}
int main()
{
	scanf("%d%d%d",&n,&s,&q);
	for(int i=1;i<=s;i++)
	{
		bt.reset();
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			bt[x-1]=1;
		}	
		alm=1<<cnt1;
		for(int j=0;j<n;j++)
		{
			if(bt[j]==0)continue;
			if(basstr[j]==0)
			{
				bas[j]=bt;
				basstr[j]=alm;
				cnt1++;
				goto tag;
			}
			bt^=bas[j];
			alm^=basstr[j];
		}
		alm^=1<<cnt1;
		cnt2++;
		str[cnt2-1]=alm;
		tag:;
	}
	for(int i=1;i<32768;i++)dp[i]=10000,dp2[i]=10000;
	dp[0]=0;dp2[0]=0;
	if(cnt1<=15)solve1();
	else solve2();
	for(int i=1;i<=q;i++)
	{
		bt.reset();
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x);
			bt[x-1]=1;
		}	
		alm=0;
		for(int j=0;j<n;j++)
		{
			if(bt[j]==0)continue;
			if(basstr[j]==0)
			{
				printf("-1\n");
				goto tag2;
			}
			bt^=bas[j];
			alm^=basstr[j];
		}
		if(cnt1<=15)printf("%d\n",dp[alm]);
		else 
		{
			int ans=__builtin_popcount(alm);
			for(int j=0;j<(1<<cnt2);j++)ans=min(ans,__builtin_popcount(j)+__builtin_popcount(dp[j]^alm));
			printf("%d\n",ans);
		}
		tag2:;
	}
	return 0;
}