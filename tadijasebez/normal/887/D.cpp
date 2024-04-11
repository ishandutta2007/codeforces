#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=300050;
ll dp1[N],dp2[N];
int x[N];
map<ll,int> Map;
int main()
{
	int n,a,b,c,d,start,len,i,t;
	scanf("%i %i %i %i %i %i %i",&n,&a,&b,&c,&d,&start,&len);
	dp1[0]=start;
	dp2[0]=start;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x[i],&t);
		if(t==0) dp1[i]=dp1[i-1]-b,dp2[i]=dp2[i-1]-d;
		else dp1[i]=dp1[i-1]+a,dp2[i]=dp2[i-1]+c;
	}
	int j=1;
	x[0]=-1;
	Map[start]++;
	for(i=0;i<=n;i++)
	{
		if(dp1[i]<0) return printf("-1\n"),0;
		while(j<=n && x[j]-(x[i]+1)<len) Map[dp2[j]]++,j++;
		Map[dp2[i]]--;if(!Map[dp2[i]]) Map.erase(dp2[i]);
		if(Map.empty()) return printf("%i\n",x[i]+1),0;
		ll tmp=Map.begin()->first;
		if(tmp-dp2[i]+dp1[i]>=0) return printf("%i\n",x[i]+1),0;
	}
	return 0;
}