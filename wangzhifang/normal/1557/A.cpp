#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 300000
ll a[max_n+1];
il void test(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(int i=2; i<=n; ++i)
		a[i]+=a[i-1];
	double ans=-1e30;
	for(int i=1; i<n; ++i){
		double tmp=double(a[i])/i+double(a[n]-a[i])/(n-i);
		if(tmp>ans)
			ans=tmp;
	}
	printf("%lf\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}