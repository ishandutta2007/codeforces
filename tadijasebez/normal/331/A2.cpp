#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
#define mp make_pair
#define ll long long
const int N=300050;
const ll inf=9e18;
map<int,int> fir;
ll dp[N],sol=-inf;
pair<int,int> res;
vector<int> del;
int a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+(a[i]<0?0:a[i]);
		if(fir[a[i]])
		{
			ll ans=dp[i]-dp[fir[a[i]]-1];
			if(a[i]<0) ans+=2*a[i];
			if(ans>sol)
			{
				sol=ans;
				res=mp(fir[a[i]],i);
			}
		}
		else fir[a[i]]=i;
	}
	printf("%lld ",sol);
	for(i=1;i<res.first;i++) del.push_back(i);
	for(i=res.first+1;i<res.second;i++) if(a[i]<0) del.push_back(i);
	for(i=res.second+1;i<=n;i++) del.push_back(i);
	printf("%i\n",del.size());
	for(i=0;i<del.size();i++) printf("%i ",del[i]);
	printf("\n");
	return 0;
}