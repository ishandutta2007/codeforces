#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
il void test(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	if(a+b>n-2){
		puts("-1");
		return;
	}
	if(a==b+1){
		for(int i=1; i<=a; ++i)
			printf("%d %d ",i,n+1-i);
		for(int i=2*a; ++i<=n; printf("%d ",n+1-i+a));
		putchar('\n');
		return;
	}
	if(b==a+1){
		for(int i=1; i<=b; ++i)
			printf("%d %d ",n+1-i,i);
		for(int i=2*b; ++i<=n; printf("%d ",i-b));
		putchar('\n');
		return;
	}
	if(b==a){
		for(int i=1; i<=a; ++i)
			printf("%d %d ",i,n+1-i);
		for(int i=2*a; ++i<=n; printf("%d ",i-a));
		putchar('\n');
		return;
	}
	puts("-1");
	return;
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}