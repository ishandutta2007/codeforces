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
	if(k<=4){
		printf("%d\n",k/2+n-k);
		for(int i=1; i*2<=k; ++i)
			printf("%d ",i);
		for(int i=k+1; i<=n; ++i)
			printf("%d ",i);
		puts("");
		return;
	}
	printf("%d\n",k/2+n-k);
	for(int i=(k+1)/2; i<k; ++i)
		printf("%d ",i);
	for(int i=k+1; i<=n; ++i)
		printf("%d ",i);
	puts("");
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}