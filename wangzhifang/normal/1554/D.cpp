#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n;
	scanf("%d",&n);
	if(n==1){
		puts("a");
		return;
	}
	if(n==2){
		puts("ab");
		return;
	}
	if(n==3){
		puts("abc");
		return;
	}
	int m=n>>1;
	for(int i=1; i<=m; ++i)
		putchar('a');
	putchar('b');
	for(int i=1; i<m; ++i)
		putchar('a');
	if((n&1))
		putchar('c');
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}