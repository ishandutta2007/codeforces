#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long int
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
const int N=500050;
int dp[N],sum[N],a[N];
int main()
{
	int n,k,d,i;
	scanf("%i %i %i",&n,&k,&d);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	dp[0]=sum[0]=1;
	int j=1;
	for(i=1;i<=n;i++)
	{
		while(a[i]-a[j]>d) j++;
		if(j>i-k+1) dp[i]=0;
		else
		{
			if((i-k>=0?sum[i-k]:0)>(j-2>=0?sum[j-2]:0)) dp[i]=1;
		}
		sum[i]=sum[i-1]+dp[i];
	}
	if(dp[n]) printf("YES\n");
	else printf("NO\n");
	return 0;
}