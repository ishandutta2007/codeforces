#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[max_n+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	for(; n&&a[n]==n; --n);
	double ans=1;
	for(int i=1,x; i<=m; ++i){
		double p;
		scanf("%d%lf",&x,&p);
		if(x>=n)
			ans*=1-p;
	}
	printf("%lf\n",n?1-ans:1);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}