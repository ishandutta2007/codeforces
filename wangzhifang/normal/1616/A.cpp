#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=200000;
int a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=2; i<=n; ++i)
		if(a[i]==a[i-1])
			a[i-1]=-a[i-1];
	sort(a+1,a+n+1);
	printf("%d\n",int(unique(a+1,a+n+1)-a-1));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}