#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	ll n;
	scanf("%lld",&n);
	if((n%2050)){
		puts("-1");
		return;
	}
	n/=2050;
	int ans=0;
	while(n){
		ans+=n%10;
		n/=10;
	}
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}