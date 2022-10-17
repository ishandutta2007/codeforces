#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD=998244353;

int n;
ll fac[1000005],inv[1000005],ans;

ll C(int a,int b){
	return fac[a]*inv[b]%MOD*inv[a-b]%MOD;
}

int main(){
	scanf("%d",&n);
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for (int i=2;i<=n;++i) fac[i]=fac[i-1]*i%MOD,inv[i]=(ll)(MOD-MOD/i)*inv[MOD%i]%MOD;
	for (int i=2;i<=n;++i) inv[i]=inv[i-1]*inv[i]%MOD;
	for (int a=1;a<=n;++a){
		(ans+=(fac[a]-1)*fac[n-a]%MOD*C(n,a))%=MOD;
	}
	printf("%I64d\n",(ans+1+MOD)%MOD);
	return 0;
}