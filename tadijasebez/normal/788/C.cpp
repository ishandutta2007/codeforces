#include <stdio.h>
#include <bitset>
#include <vector>
using namespace std;
bitset<2050> tmp,dp;
bool mark[1050];
vector<int> vals;
int main()
{
	int k,n,i,x,j;
	scanf("%i %i",&k,&n);
	for(i=0;i<n;i++) scanf("%i",&x),mark[x]=true;
	for(i=0;i<=1000;i++) if(mark[i]) vals.push_back(i-k);
	dp.set(1000);
	for(i=1;i<=1000;i++)
	{
		tmp=0;
		for(j=0;j<vals.size();j++)
		{
			if(vals[j]>0) tmp|=dp<<vals[j];
			else tmp|=dp>>(-vals[j]);
		}
		dp=tmp;
		if(dp.test(1000))
		{
			printf("%i\n",i);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}