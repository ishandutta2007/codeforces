#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef cs int& ci;
typedef long long ll;
constexpr int max_n=200000;
int a[max_n+1];
il bool chk(int x){
	for(int i=2,ed=sqrt(x); i<=ed; ++i)
		if(!(x%i))
			return 0;
	return 1;
}
il void test(){
	int n,e;
	scanf("%d%d",&n,&e);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	ll ans=0;
	for(int i=1; i<=n; ++i)
		if(a[i]>1&&chk(a[i])){
			int l=1,r=1;
			for(int j=i; (j-=e)>0&&a[j]==1; ++l);
			for(int j=i; (j+=e)<=n&&a[j]==1; ++r);
			ans+=ll(l)*r-1;
		}
	printf("%lld\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}