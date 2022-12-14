#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il void test(){
	int n;
	scanf("%d",&n);
	printf("%d\n",(n+1)/10);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}