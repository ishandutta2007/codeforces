#include <cstdio>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define max_k 5000
int s[5010][5010],ans,x,M=1e9+7;
ll quickpow(ll x,int k,ll ret=1){
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	s[1][1]=1;
	for(int i=2; i<=k; ++i)
		for(int j=1; j<=k; ++j)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*ll(j))%mod;
	ll x=1;
	for(int i=1; i<=k; ++i)
		ans=(ans+quickpow(2,mod-1+n-i,s[k][i]*(x=x*(n-i+1)%mod)%mod))%mod;
	printf("%d\n",ans);
	return 0;
}