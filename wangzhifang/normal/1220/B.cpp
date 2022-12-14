#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 1000
int m[max_n+1][max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",m[i]+j);
	int x=m[1][3],y=m[2][3];
	int d=__gcd(x,y);
	x/=d,y/=d;
	int t=sqrt(m[1][2]/x/y);
	x*=t;
	printf("%d",x);
	for(int i=2; i<=n; ++i)
		printf(" %d",m[1][i]/x);
	puts("");
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}