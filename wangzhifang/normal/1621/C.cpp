#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=10000;
int p[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	memset(p+1,0,n<<2);
	for(int i=1; i<=n; ++i)
		if(!p[i]){
			printf("? %d\n",i);
			fflush(stdout);
			int x;
			scanf("%d",&x);
			for(int y; !p[x]; x=y){
				printf("? %d\n",i);
				fflush(stdout);
				scanf("%d",&y);
				p[x]=y;
			}
		}
	printf("!");
	for(int i=1; i<=n; ++i)
		printf(" %d",p[i]);
	printf("\n");
	fflush(stdout);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}