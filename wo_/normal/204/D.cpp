#include<cstdio>

using namespace std;

const long long mod=1000000007;

int black[1001000],white[1001000],x[1001000];
long long black_dp[1001000],black_sum[1001000],white_dp[1001000],white_sum[1001000];
long long exp2[1001000];

char ch[1001000],in[1001000];

int main()
{
	exp2[0]=1;
	for(int i=1;i<1001000;i++)
	{
		exp2[i]=exp2[i-1]*2;
		exp2[i]%=mod;
	}
	int N,K;
	scanf("%d%d",&N,&K);
	scanf("%s",in);
	for(int i=0;i<N;i++) ch[i+1]=in[i];
	ch[0]='S';
	black[0]=0,white[0]=0,x[0]=0;
	for(int i=1;i<=N;i++)
	{
		black[i]=black[i-1];white[i]=white[i-1];x[i]=x[i-1];
		if(ch[i]=='B') black[i]++;
		if(ch[i]=='W') white[i]++;
		if(ch[i]=='X') x[i]++;
	}
	black[N+1]=black[N];white[N+1]=white[N];x[N+1]=x[N];
	black_dp[0]=0;black_sum[0]=0;
	for(int i=1;i<K;i++)
	{
		black_dp[i]=0;black_sum[i]=0;
	}
	if(white[K]==0)
	{
		black_dp[K]=1;
		black_sum[K]=1;
	}
	else
	{
		black_dp[K]=0;
		black_sum[K]=0;
	}
	for(int i=K+1;i<=N;i++)
	{
		if(ch[i]=='X')
		{
			black_sum[i]=black_sum[i-1]*2;
		}
		else
		{
			black_sum[i]=black_sum[i-1];
		}
		if(white[i]-white[i-K]!=0)
		{
			black_dp[i]=0;
			//black_sum[i]=black_sum[i-1];
		}
		else if(ch[i-K]=='B')
		{
			black_dp[i]=0;
			//black_sum[i]=black_sum[i-1];
		}
		else
		{
			black_dp[i]=exp2[x[i-K-1]];
			black_dp[i]-=black_sum[i-K-1];
			//black_sum[i]=black_sum[i-1]+black_dp[i];
			black_sum[i]+=black_dp[i];
			black_sum[i]%=mod;
		}
		black_sum[i]%=mod;
	}
	white_dp[N+1]=0;white_sum[N+1]=0;
	for(int i=N;i>N-K+1;i--)
	{
		white_dp[i]=0;white_sum[i]=0;
	}
	if(black[N]-black[N-K]!=0)
	{
		white_dp[N-K+1]=0;white_sum[N-K+1]=0;
	}
	else
	{
		white_dp[N-K+1]=1;
		white_sum[N-K+1]=1;
	}
	for(int i=N-K;i>=1;i--)
	{
		if(ch[i]=='X')
		{
			white_sum[i]=white_sum[i+1]*2;
		}
		else
		{
			white_sum[i]=white_sum[i+1];
		}
		if(black[i+K-1]-black[i-1]!=0)
		{
			white_dp[i]=0;
			//white_sum[i]=white_sum[i+1];
		}
		else if(ch[i+K]=='W')
		{
			white_dp[i]=0;
			//white_sum[i]=white_sum[i+1];
		}
		else
		{
			white_dp[i]=exp2[x[N]-x[i+K]];
			white_dp[i]-=white_sum[i+K+1];
			white_sum[i]+=white_dp[i];
		}
		white_sum[i]%=mod;
	}
	long long ans=0;
	for(int i=1;i<=N-1;i++)
	{
		ans+=(black_dp[i]*white_sum[i+1]);
		ans%=mod;
	}
	ans+=mod;
	ans%=mod;
	printf("%d\n",(int)ans);
	return 0;
}