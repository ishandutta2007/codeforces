#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	if(k*2-1>n){
		puts("-1");
		return;
	}
	for(int i=1; i<=n; ++i){
		for(int j=1; j<i; ++j)
			putchar('.');
		if((i&1)&&k){
			putchar('R');
			--k;
		}
		else
			putchar('.');
		for(int j=i; ++j<=n; putchar('.'));
		putchar('\n');
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}