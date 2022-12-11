#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	ll x,y;
	scanf("%lld%lld",&x,&y);
	if(y<x){
		printf("%lld\n",x+y);
		return;
	}
	if(x==y){
		printf("%lld\n",x);
		return;
	}
	printf("%lld\n",y-(y%x)/2);
} 
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}