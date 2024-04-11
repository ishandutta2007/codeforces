//CF713C
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define max_n 3000
#define max_m max_n
int a[max_n+1],val[max_n+1];
ll dp[max_m+1];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1,x; i<=n; ++i){
		scanf("%d",&x);
		a[i]=val[i]=x-i;
//		printf("%d\n",a[i]);
	}
	sort(val+1,val+n+1);
	const int m=unique(val+1,val+n+1)-val-1;
	for(int i=1; i<=n; ++i){
		ll mn=dp[1];
		for(int j=1; j<=m; ++j){
			if(dp[j]<mn)
				mn=dp[j];
			dp[j]=mn+abs(val[j]-a[i]);
//			printf("(%d,%d):%d\n",i,j,dp[j]);
		}
	}
	ll ans=dp[m];
	for(int i=m; --i; dp[i]<ans&&(ans=dp[i]));
	printf("%lld\n",ans);
	return 0;
}