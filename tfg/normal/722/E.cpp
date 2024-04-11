#include <cstdio>
#include <algorithm>
#include <utility>

typedef std::pair<int,int> ii;

bool comp(ii a, ii b)
{
	return a.first+a.second<b.first+b.second;
}

const long long int MOD=1e9+7;

long long int fat[200100];
long long int ifat[200100];

ii an[2020];

long long int dp[2020][22];

long long int qexp(long long int x, int e)
{
	long long int now=1;
	for(;e;e=e>>1)
	{
		if(e&1)
			now=(now*x)%MOD;
		x=(x*x)%MOD;
	}
	return now;
}

long long int comb(int a, int b)
{
	return (((fat[a]*ifat[b])%MOD)*ifat[a-b])%MOD;
}

long long int paths(int i, int j)
{
	if(i>j || an[i].first>an[j].first || an[i].second>an[j].second) return 0;
	int dx=an[j].first-an[i].first;
	int dy=an[j].second-an[i].second;
	return comb(dx+dy,dx);
}

int main()
{
	int n,m,k,s;

	fat[0]=fat[1]=1;

	for(int i=2;i<200010;i++)
	{
		fat[i]=(fat[i-1]*i)%MOD;
	}
	for(int i=0;i<100010;i++)
	{
		ifat[i]=qexp(fat[i],MOD-2);
	}

	scanf("%i %i %i %i",&n,&m,&k,&s);
	for(int i=1;i<=k;i++)
	{
		scanf("%i %i",&an[i].first,&an[i].second);
	}
	std::sort(an+1,an+k+1,comp);
	//for(int i=1;i<=k;i++)
	//	printf("%i %i\n",an[i].first,an[i].second);
	an[k+1]=ii(n,m);
	an[0]=ii(1,1);

	for(int i=k;i>=0;i--)
	{
		dp[i][0]=paths(i,k+1);
		//printf("initially %lli paths\n",dp[i][0]);
		for(int j=i+1;j<=k;j++)
		{
			//printf("subtracting %lli,paths=%lli,dp=%lli\n",paths(i,j)*dp[j][0],paths(i,j),dp[j][0]);
			dp[i][0]=(MOD+dp[i][0]-((paths(i,j)*dp[j][0])%MOD))%MOD;
		}
		//printf("%lli paths go through %i an after %i\n",dp[i][0],0,i);
	}
	for(int i=1;i<20;i++)
	{
		for(int j=k;j>=0;j--)
		{
			dp[j][i]=paths(j,k+1);
			for(int w=0;w<i;w++)
				dp[j][i]=(dp[j][i]-dp[j][w]+MOD)%MOD;
			for(int w=j+1;w<=k;w++)
				dp[j][i]=(dp[j][i]-((dp[w][i]*paths(j,w))%MOD)+MOD)%MOD;
			//printf("%lli paths go through %i an after %i\n",dp[j][i],i,j);
		}
	}
	long long int ans=(dp[0][0]*s)%MOD;
	long long int count=dp[0][0];
	//printf("%lli paths go through %i an.\n",dp[0][0],0);
	for(int i=1;i<20;i++)
	{
		//printf("%lli paths go through %i an.\n",dp[0][i],i);
		s=(s+1)/2;
		ans=(ans+dp[0][i]*s)%MOD;
		count=(count+dp[0][i])%MOD;
	}
	ans=(ans+((paths(0,k+1)-count+MOD)%MOD))%MOD;
	ans=(ans*qexp(paths(0,k+1),MOD-2))%MOD;
	printf("%lli\n",ans);
}