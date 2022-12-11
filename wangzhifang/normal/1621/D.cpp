#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef long long ll;
constexpr int max_n=250;
int a[max_n*2+1][max_n*2+1];
il void test(){
	int n,m;
	scanf("%d",&n);
	m=n<<1;
	for(int i=1; i<=m; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",a[i]+j);
	ll ans=0;
	for(int i=n; ++i<=m; )
		for(int j=n; ++j<=m; )
			ans+=a[i][j];
	printf("%lld\n",ans+min({a[1][n+1],a[1][m],a[n][n+1],a[n][m],a[n+1][1],a[n+1][n],a[m][1],a[m][n]}));
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}