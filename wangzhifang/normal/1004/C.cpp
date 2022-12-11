#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 100000
int a[max_n+1],ton[max_n+1],vis[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	int /*cnt1=0,*/cnt2=0;
	for(int i=1; i<=n; ++i){
		scanf("%d",a+i);
		cnt2+=(++ton[a[i]]==1);
	}
	ll ans=ll(cnt2)*cnt2;
	for(int i=1; i<=n; ++i)
		if(ton[a[i]]==1)
			--ans;
//	printf("%lld\n",ans);
	for(int i=1; i<=n; ++i){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			--cnt2;
		}
		if(!--ton[a[i]]){
			ans-=cnt2;
		}
	}
	printf("%lld\n",ans);
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}