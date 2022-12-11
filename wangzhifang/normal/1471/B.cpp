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
	int n,x,t=2147483647;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		int y=a[i],cnt=0;
		while(!(y%x))
			y/=x,++cnt;
		cnt<t&&(t=cnt);
	}
	++t;
	ll ans=0;
	for(int i=1; i<=n; ++i){
		int y=a[i],cnt=0;
		while(!(y%x))
			y/=x,++cnt;
		cnt<t&&(t=cnt);
		ans+=a[i]*ll(t+1);
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}