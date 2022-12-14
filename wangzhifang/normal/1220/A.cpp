#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
int cnt[256];
il void test(){
	int n;
	scanf("%d\n",&n);
	for(int i=1; i<=n; ++i)
		++cnt[getchar()];
	for(int i=cnt['n']; i; --i)
		printf("1 ");
//	if(cnt['n'])
		for(int i=cnt['z']; i; --i)
			printf("0 ");
//	else
//		putchar('0');
	puts("");
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}