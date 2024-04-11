#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

const long long mod=1000000007;

vector<int> pls;

long long dp[300300]={};
long long sum[300300]={};

int ss[100100],ts[100100];

vector<int> les[300300];

int main()
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++)
	{
		scanf("%d%d",ss+i,ts+i);
		pls.push_back(ss[i]);pls.push_back(ts[i]);
	}
	pls.push_back(0);pls.push_back(N);
	sort(pls.begin(),pls.end());
	pls.erase(unique(pls.begin(),pls.end()),pls.end());
	for(int i=0;i<M;i++)
	{
		int sid=distance(pls.begin(),lower_bound(pls.begin(),pls.end(),ss[i]));
		int tid=distance(pls.begin(),lower_bound(pls.begin(),pls.end(),ts[i]));
		les[tid].push_back(sid);
	}
	dp[0]=1;
	sum[0]=1;
	int tmp=pls.size()-1;
	N=tmp;
	for(int i=1;i<=N;i++)
	{
		long long tmp=0;
		for(int j=0;j<les[i].size();j++)
		{
			if(les[i][j]==0)
			{
				tmp+=sum[i-1];
			}
			else
			{
				tmp+=(sum[i-1]-sum[les[i][j]-1]);
			}
			tmp%=mod;
		}
		dp[i]=tmp;
		sum[i]=sum[i-1]+dp[i];
		sum[i]%=mod;
	}
	dp[N]%=mod;
	dp[N]+=mod;
	dp[N]%=mod;
	printf("%d\n",(int)dp[N]);
	return 0;
}