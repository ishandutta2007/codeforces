#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	ll n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);
	if(m<n-1||m>n*(n-1)/2||k<=1){
		puts("NO");
		return;
	}
	if(n==1){
		puts("YES");
		return;
	}
	if(k==2){
		puts("NO");
		return;
	}
	if(m==n*(n-1)/2){
		puts("YES");
		return;
	}
	if(k==3)
		puts("NO");
	else
		puts("YES");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}