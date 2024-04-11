#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; ++i)
		putchar('a'+(i%3));
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}