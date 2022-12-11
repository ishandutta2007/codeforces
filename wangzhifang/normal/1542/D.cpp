#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define mod 998244353
#define max_n 500
void mod1(int&x){
	x>=mod&&(x-=mod);
}
int a[max_n+1],dp[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1,x; i<=n; ++i){
		char ch;
		scanf("\n%c",&ch);
		if(ch=='-')
			a[i]=0;
		else{
			scanf("%d",&x);
			a[i]=x;
		}
	}
	ll ans=0;
	for(int i=1; i<=n; ++i)
		if(a[i]){
			memset(dp,0,sizeof(dp));
			dp[0]=1;
			for(int j=1; j<=n; ++j){
				if(i!=j){
					if(a[j]){
						if(a[i]<a[j]||a[i]==a[j]&&i<j)
							for(int k=0; k<=j; ++k)
								mod1(dp[k]<<=1);
						else
							for(int k=j; k; --k)
								mod1(dp[k]+=dp[k-1]);
					}
					else{
						if(j<i)
							mod1(dp[0]<<=1);
						for(int k=0; k<j; ++k)
							mod1(dp[k]+=dp[k+1]);
					}
				}
			}
			ll sum=0;
			for(int j=0; j<=n; ++j)
				sum+=dp[j];
			ans=(ans+sum%mod*a[i])%mod;
		}
	printf("%lld\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}