#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,x;
	scanf("%d%d",&n,&x);
	ll sum=0,ans=0;
	for(int i=1,k; i<=n; ++i){
		scanf("%d",&k);
		sum+=k,ans+=(k-1)/x+1;
	}
	printf("%lld %lld\n",(sum-1)/x+1,ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}