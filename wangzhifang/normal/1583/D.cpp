#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100
int x[max_n+1],p[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	int y=n;
	for(int i=2; i<=n; ++i){
		putchar('?');
		for(int j=1; j<n; ++j)
			printf(" %d",i);
		puts(" 1");
		fflush(stdout);
		scanf("%d",x+i-1);
		if(!x[i-1]){
			y=i-1;
			break;
		}
	}
	for(int i=1; i<y; ++i)
		p[x[i]]=y-i;
	p[n]=y;
	for(int i=n-y; i; --i){
		putchar('?');
		for(int j=1; j<n; ++j)
			printf(" 1");
		printf(" %d\n",i+1);
		fflush(stdout);
		int t;
		scanf("%d",&t);
		p[t]=y+i;
	}
	putchar('!');
	for(int i=1; i<=n; ++i)
		printf(" %d",p[i]);
	puts("");
	fflush(stdout);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}