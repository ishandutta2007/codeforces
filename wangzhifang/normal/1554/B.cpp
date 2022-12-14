#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[max_n+1];
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	ll ans=-1e18;
	for(int i=n; --i; ){
		ll s=ll(i)*n,p=ll(i)*n-k*ll(a[i]),t;
		for(int j=n; j>i&&p>ans; s-=i,p-=i,--j)
			if((t=s-k*ll(a[i]|a[j]))>ans)
				ans=t;
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}