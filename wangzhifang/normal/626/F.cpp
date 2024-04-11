#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
constexpr int max_n=200,max_k=1000;
int a[max_n+1];
int dp[2][max_n/2+1][max_k+1];
typedef int arr[max_k+1];
int main(){
//	freopen("simple.in","r",stdin);
//	freopen("simple.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	a[0]=0;
	dp[0][0][0]=1;
	memset(dp[0][0]+1,0,k<<2);
	for(int i=1; i<=n; ++i){
//		printf("a[%d]=%d\n",i,a[i]);
		arr*now=dp[i&1],*prv=dp[bool(i&1)^1];
		const int d=a[i]-a[i-1],lim=min(i-1,n-i+1);
		for(int j=0,ed=min(i,n-i); j<=ed; ++j)
			for(int l=0; l<=k; ++l){
				ll sum=0;
				int tmp=l-d*j;
//				printf("%d %d %d: ",i,j,l);
				if(j<=lim&&tmp>=0&&tmp<=k)
					sum+=prv[j][tmp]*ll(j+1)/*,printf("(a)%d*%d ",prv[j][tmp],j+1)*/;
				tmp+=d;
				if(j>0&&j-1<=lim&&tmp>=0&&tmp<=k)
					sum+=prv[j-1][tmp]/*,printf("(b)%d ",prv[j-1][tmp])*/;
				tmp-=d<<1;
				if(j<lim&&tmp>=0&&tmp<=k)
					sum+=prv[j+1][tmp]*ll(j+1)/*,printf("(c)%d ",prv[j+1][tmp])*/;
//				printf(" = %lld\n",sum);
//				if(sum)
//					printf("%d %d %d: %lld\n",i,j,l,sum);
				now[j][l]=sum%mod;
			}
	}
	int*now=dp[n&1][0];
	ll ans=0;
	for(int i=0; i<=k; ++i)
		ans+=now[i];
	printf("%lld\n",ans%mod);
	return 0;
}