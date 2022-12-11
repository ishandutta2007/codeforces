#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=998244353;
constexpr int max_n=200000;
ll a[max_n+1];
void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	const int m=min(n,k);
	const ll anst=ll(k*2-m-1)*m/2;
	a[0]=0;
	ll mx=0;
	for(int i=1; i<=n; ++i){
		scanf("%lld",a+i);
		a[i]+=a[i-1];
		if(i>=m&&a[i]-a[i-m]>mx)
			mx=a[i]-a[i-m];
	}
	printf("%lld\n",anst+mx);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}