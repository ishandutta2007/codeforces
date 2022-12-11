#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
il bool chk(int x){
	for(int i=2,ed=sqrt(x); i<=ed; ++i)
		if(x%i==0)
			return 1;
	return 0;
}
int a[201];
il void test(){
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		sum+=a[i];
	}
//	printf("*%d\n",sum);
	if(chk(sum)){
		printf("%d\n",n);
		for(int i=1; i<=n; ++i)
			printf("%d ",i);
		putchar('\n');
		return;
	}
	printf("%d\n",n-1);
	for(int i=1; i<=n; ++i)
		if((a[i]&1)){
			for(int j=1; j<i; ++j)
				printf("%d ",j);
			for(int j=n; j>i; --j)
				printf("%d ",j);
			break;
		}
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}