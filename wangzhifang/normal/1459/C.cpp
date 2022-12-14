#include <cstdio>
#include <algorithm>
#define cs const
#define il inline
#define max_n 200000
using namespace std;
typedef long long ll;
ll a[max_n+1];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	if(n==1){
		ll x,y;
		scanf("%lld",&x);
		for(int i=1; i<=m; ++i){
			scanf("%lld",&y);
			printf("%lld ",x+y);
		}
		return 0;
	}
	for(int i=1; i<=n; ++i)
		scanf("%lld",a+i);
	sort(a+1,a+n+1);
	ll ans=a[2]-a[1];
	for(int i=2; i<n; ++i)
		ans=__gcd(ans,a[i+1]-a[i]);
	ll x;
	for(int i=1; i<=m; ++i){
		scanf("%lld",&x);
		printf("%lld ",__gcd(x+a[1],ans));
	}
	return 0;
}