#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100
int a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=1; i<=n; ++i){
		if(a[i]){
//			printf("*%d\n",i);
			++ans;
			for(int j=n; j>=i; /*printf(" %d\n",j),*/--j)
				if(!(a[j]%a[i]))
					a[j]=0;
		}
	}
	printf("%d\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}