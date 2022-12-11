#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
#define max_m 300000
int k[max_n+1],c[max_m+1];
ll prv[max_m+1];
il void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",k+i);
	sort(k+1,k+n+1);
	for(int j=1; j<=m; ++j)
		scanf("%d",c+j);
	int cnt=0;
	for(int i=1; i<=n; ++i)
		if(cnt<k[i])
			++cnt;
	ll ans=9223372036854775807,sum=0;
	prv[1]=c[1];
	for(int i=2; i<=m; ++i)
		prv[i]=prv[i-1]+c[i];
	for(int i=n-cnt; i; --i)
		sum+=c[k[i]];
	for(int i=0; i<cnt; ++i){
		ll tmp=sum+prv[cnt-i];
		tmp<ans&&(ans=tmp);
		sum+=c[k[n-cnt+i+1]];
	}
	sum<ans&&(ans=sum);
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}