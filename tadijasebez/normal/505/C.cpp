#include <stdio.h>
#include <map>
using namespace std;
const int N=30051;
const int H=1000;
//map<int,int> dp[N];
//map<int,int>::iterator it;
int dp[N][H];
int w[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,d,i,j,x;
	scanf("%i %i",&n,&d);
	while(n--) scanf("%i",&x),w[x]++;
	for(i=0;i<N;i++) for(j=0;j<H;j++) dp[i][j]=-1;
	int lo=d-500;
	dp[d][d-lo]=w[0]+w[d];
	int sol=0;
	for(i=1;i<=N-50;i++)
	{
		//for(it=dp[i].begin();it!=dp[i].end();it++)
		for(j=0;j<H;j++)
		{
			int dist=j+lo;//it->first;
			int val=dp[i][j];//it->second;
			if(val<0) continue;
			if(dist>1 && i+dist-1<N) dp[i+dist-1][dist-1-lo]=max(dp[i+dist-1][dist-1-lo],val+w[i+dist-1]);
			if(i+dist<N) dp[i+dist][dist-lo]=max(dp[i+dist][dist-lo],val+w[i+dist]);
			if(i+dist+1<N) dp[i+dist+1][dist+1-lo]=max(dp[i+dist+1][dist+1-lo],val+w[i+dist+1]);
			sol=max(sol,val);
		}
	}
	//for(i=0;i<H;i++) sol=max(sol,dp[N-50][i]);
	//for(it=dp[N-50].begin();it!=dp[N-50].end();it++) sol=max(sol,it->second);
	printf("%i\n",sol);
	return 0;
}