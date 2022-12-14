#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_n 100000
int prv[max_n+1],x[max_n+1];
ll dp[max_n+1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
		scanf("%d",x+i);
	int pos=1;
	prv[1]=-n,dp[n]=0;
	ll ans=0;
	for(int i=n; --i; ){
		int u=-*lower_bound(prv+1,prv+pos+1,-x[i]);
		dp[i]=dp[u]-(x[i]-u)+(n-i);
		ans+=dp[i];
		while(pos&&x[-prv[pos]]<=x[i])
			--pos;
		prv[++pos]=-i;
	}
	printf("%lld\n",ans);
	return 0;
}