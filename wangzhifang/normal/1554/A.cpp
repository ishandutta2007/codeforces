#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,lst;
	scanf("%d%d",&n,&lst);
	ll ans=0;
	for(int i=n,x; --i; lst=x){
		scanf("%d",&x);
		ll(x)*lst>ans&&(ans=x*ll(lst));
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}