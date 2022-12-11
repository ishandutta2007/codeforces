#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a>ll(b)*c){
		puts("-1");
		return;
	}
	if(d>c)
		d=c;
	if(a<=ll(b)*d){
		printf("%d\n",a);
		return;
	}
	ll k=int(double(a)/b/d)+1;
	ll u=((2*a+ll(b)*d)*k-ll(b)*d*k*k)/2;
	printf("%lld\n",u);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}