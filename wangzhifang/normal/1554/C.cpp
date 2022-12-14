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
	++m;
	int t=(m|n)^m,k=1;
	for(; k<=t; k<<=1);
//	printf("%d %d %d %d\n",n,m,t,k);
	int l=(m&(~(k-1)))|n;
	printf("%d\n",l^n);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}