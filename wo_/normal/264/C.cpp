#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const long long inf=1ll<<60;

long long dp[100100];
int cs[100100];
int vals[100100];

long long Ma[2];

int main()
{
	int N,Q;
	scanf("%d%d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		scanf("%d",vals+i);
	}
	for(int i=0;i<N;i++)
	{
		scanf("%d",cs+i);
		cs[i]--;
	}
	for(int datano=0;datano<Q;datano++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int j=0;j<N;j++) dp[j]=-inf;
		Ma[0]=-inf,Ma[1]=-inf;
		for(int i=0;i<N;i++)
		{
			int color=cs[i];
			//differnt color
			long long tmp=(long long)b*vals[i];
			long long prev=0;
			if(dp[color]==Ma[0]) prev=max(prev,Ma[1]);
			else prev=max(prev,Ma[0]);
			long long best_dif=prev+tmp;
			//same color
			long long best_same=-inf;
			tmp=(long long)a*vals[i];
			if(dp[color]!=-inf) best_same=dp[color]+tmp;
			long long nxt=max(best_same,best_dif);
			nxt=max(nxt,dp[color]);
			//update
			long long a=dp[color];
			if(Ma[1]>a)
			{
				if(Ma[0]>=nxt&&Ma[1]<nxt)
				{
					Ma[1]=nxt;
				}
				else if(Ma[0]<nxt)
				{
					Ma[1]=Ma[0];
					Ma[0]=nxt;
				}
			}
			else if(Ma[1]==a)
			{
				Ma[1]=nxt;
				if(Ma[0]<Ma[1]) swap(Ma[0],Ma[1]);
			}
			else if(Ma[0]==a)
			{
				Ma[0]=nxt;
			}
			dp[color]=nxt;
		}
		long long ans=0;
		for(int i=0;i<N;i++) ans=max(ans,dp[i]);
		cout<<ans<<"\n";
	}
	return 0;
}