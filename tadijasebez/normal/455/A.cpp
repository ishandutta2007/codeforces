#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
long long cnt[N];
long long dp[N];
long long max(long long a, long long b){ return a>b?a:b;}
int main()
{
	int n,x,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&x),cnt[x]++;
	dp[1]=cnt[1];
	for(i=2;i<N;i++) dp[i]=max(dp[i-1],dp[i-2]+cnt[i]*i);
	printf("%lld\n",dp[N-1]);
	return 0;
}