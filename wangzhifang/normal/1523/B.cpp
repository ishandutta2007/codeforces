#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=n; i; --i)
		scanf("%*d");
	printf("%d\n",3*n);
	for(int i=2; i<=n; i+=2){
		printf("1 %d %d\n",i-1,i);
		printf("2 %d %d\n",i-1,i);
		printf("1 %d %d\n",i-1,i);
		printf("1 %d %d\n",i-1,i);
		printf("2 %d %d\n",i-1,i);
		printf("1 %d %d\n",i-1,i);
	}
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}