#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		printf("%d ",i+1);
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}