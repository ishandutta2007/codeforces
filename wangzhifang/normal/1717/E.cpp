#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
constexpr int mod=1000000007;
constexpr int max_n=100000;
int gcdn[max_n],phi[max_n];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
		gcdn[i]=i/__gcd(n,i),phi[i]=i;
	for(int i=1; i<n; ++i)
		for(int j=i<<1; j<n; j+=i)
			phi[j]-=phi[i];
	int ans=0;
	for(int d=1; d<n; ++d)
		for(int m=d<<1; m<n; m+=d)
//			fprintf(stderr,"*%d %d: %d*%d*%d=%lld\n",m,d,phi[m/d],gcdn[d],n-m,ll(phi[m/d])*gcdn[d]%mod*(n-m)%mod),
			ans=(ll(phi[m/d])*gcdn[d]%mod*(n-m)+ans)%mod;
	printf("%d\n",ans);
	return 0;
}