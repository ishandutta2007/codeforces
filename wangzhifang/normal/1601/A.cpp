#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 200000
int a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	int ans=0;
	for(int i=0; i<30; ++i){
		int cnt=0;
		for(int j=1; j<=n; ++j)
			if(a[j]&(1<<i))
				++cnt;
		ans=__gcd(ans,cnt);
	}
	if(!ans){
		for(int i=1; i<n; ++i)
			printf("%d ",i);
		printf("%d\n",n);
		return;
	}
	for(int i=1; i<ans; ++i)
		if(!(ans%i))
			printf("%d ",i);
	printf("%d\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}