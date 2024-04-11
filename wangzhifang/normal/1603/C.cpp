#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
constexpr int mod=998244353;
constexpr int max_n=100000,max_ai=100000;
constexpr int max_sqrt_ai=sqrt(max_ai);
int a[max_n+1];
ll ff[max_sqrt_ai+1],gg[max_sqrt_ai+1];
ll ff1[max_sqrt_ai+1],gg1[max_sqrt_ai+1];
il void test(){
	int n;
	scanf("%lld",&n);
	ll ans=0;
	a[0]=1,memset(ff,0,sizeof(ff)),memset(gg,0,sizeof(gg));
	for(int i=1; i<=n; ++i){
		scanf("%lld",a+i);
		int l1=sqrt(a[i]),l2=a[i]/(int)(sqrt(a[i])+1),x=a[i-1],y=a[i];
		for(int j=1; j<=l1; ++j){
			int lst=y/j;
			int t=(x-1)/lst;
			ll tmp=t+1;
			if(tmp*tmp<=x)
				ff1[j]=(ff[tmp]+t*ll(i-1))%mod;
			else
				ff1[j]=(gg[x/tmp]+t*ll(i-1))%mod;
		}
		ans+=ff1[1];
		for(int j=1; j<=l2; ++j){
			int t=(x-1)/j;
			ll tmp=t+1;
			if(tmp*tmp<=x)
				gg1[j]=(ff[tmp]+t*ll(i-1))%mod;
			else
				gg1[j]=(gg[x/tmp]+t*ll(i-1))%mod;
		}
		memcpy(ff+1,ff1+1,l1<<3),
		memcpy(gg+1,gg1+1,l2<<3);
	}
	printf("%lld\n",ans%mod);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}