#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1000050;
int dp[N];
int DP(int x)
{
	if(dp[x]) return dp[x];
	if(x<10) return dp[x]=x;
	int prod=1;
	int tmp=x;
	while(tmp>0)
	{
		int cif=tmp%10;
		if(cif) prod*=cif;
		tmp/=10;
	}
	return dp[x]=DP(prod);
}
vector<int> all[10];
int main()
{
	int i;
	for(i=1;i<N;i++)
	{
		DP(i);
		all[dp[i]].push_back(i);
	}
	int q,l,r,k;
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i %i",&l,&r,&k);
		int R=upper_bound(all[k].begin(),all[k].end(),r)-all[k].begin();
		int L=lower_bound(all[k].begin(),all[k].end(),l)-all[k].begin();
		printf("%i\n",R-L);
	}
	return 0;
}