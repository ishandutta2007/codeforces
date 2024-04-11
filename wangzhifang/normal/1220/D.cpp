#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n;
	vector<ll>a[65];
	scanf("%d\n",&n);
	ll x;
	for(int i=n; i; --i){
		scanf("%lld",&x);
		a[__builtin_ctzll(x)].push_back(x);
//		printf("%d\n",__builtin_ctz(x));
	}
	int mx=a[0].size(),pos=0;
	for(int i=1; i<64; ++i)
		if(a[i].size()>mx)
			mx=a[i].size(),pos=i;
	printf("%d\n",n-mx);
	for(int j=0; j<pos; ++j)
		for(ll x:a[j])
			printf("%lld ",x);
	for(int j=pos; ++j<64; )
		for(ll x:a[j])
			printf("%lld ",x);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}