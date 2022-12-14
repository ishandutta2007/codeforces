#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define mod 1000000007
il void test(){
	int n;
	ll ans=1;
	scanf("%d",&n);
	for(int i=n*2; i>2; --i)
		ans=ans*i%mod;
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}