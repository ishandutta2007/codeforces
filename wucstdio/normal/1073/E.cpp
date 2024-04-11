#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
ll l,r,k,digit[25],f[20][1<<10][2],num[20][1<<10][2];
int calc(int s)
{
	int ans=0;
	while(s)
	{
		if(s&1)ans++;
		s>>=1;
	}
	return ans;
}
ll DP(ll x,int k)
{
	if(x==0)return 0;
	digit[0]=0;
	while(x)
	{
		digit[++digit[0]]=x%10;
		x/=10;
	}
	for(int i=1;i*2<=digit[0];i++)
	  swap(digit[i],digit[digit[0]-i+1]);
	int n=digit[0];
	memset(f,0,sizeof(f));
	memset(num,0,sizeof(num));
	num[0][0][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int s=0;s<(1<<10);s++)
		{
			if(!num[i-1][s][0]&&!num[i-1][s][1])continue;
			for(int now=0;now<10;now++)
			{
				int ss=s|(1<<now);
				if(s==0&&now==0)ss=0;
				f[i][ss][0]+=f[i-1][s][0]*10+now*num[i-1][s][0];
				num[i][ss][0]+=num[i-1][s][0];
				if(now<digit[i])
				{
					f[i][ss][0]+=f[i-1][s][1]*10+now*num[i-1][s][1];
					num[i][ss][0]+=num[i-1][s][1];
				}
				if(now==digit[i])
				{
					f[i][ss][1]+=f[i-1][s][1]*10+now*num[i-1][s][1];
					num[i][ss][1]+=num[i-1][s][1];
				}
				f[i][ss][0]%=MOD;
				f[i][ss][1]%=MOD;
				num[i][ss][0]%=MOD;
				num[i][ss][1]%=MOD;
			}
		}
	}
//	ll ans=0;
//	for(int s=0;s<(1<<10);s++)
//	  if(calc(s)<=k)
//	    ans+=pos[3][s][0]*f[3][s][0]+pos[3][s][1]*f[3][s][1];
//	printf("%I64d\n",ans);
	ll ans=0;
	for(int s=0;s<(1<<10);s++)
		if(calc(s)<=k)
			ans+=f[n][s][0]+f[n][s][1];
	return ans%MOD;
}
int main()
{
	scanf("%I64d%I64d%I64d",&l,&r,&k);
	printf("%I64d\n",(DP(r,k)-DP(l-1,k)+MOD)%MOD);
	return 0;
}