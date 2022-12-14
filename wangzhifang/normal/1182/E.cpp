#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define mod 1000000007
ll t[3][3],u[3][3],ans[3][3];
void mult(ll a[3][3],ll b[3][3]){
    memset(t,0,sizeof(t));
    for(int i=0; i<3; ++i)
		for(int j=0; j<3; ++j)
			for(int k=0; k<3; ++k)
				t[i][k]=(t[i][k]+a[i][j]*b[j][k])%(mod-1);
    memcpy(b,t,sizeof(t));
}
ll quickpow(ll x,int k){
	ll ret=1;
	for(; k; k>>=1,x=x*x%mod)
		(k&1)&&(ret=ret*x%mod);
	return ret;
}
int main(){
    ll n,a,b,c,d;
    scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
    a=(a*d%mod);
    b=b*d%mod*d%mod;
    c=c*d%mod*d%mod*d%mod;
    u[0][0]=u[0][1]=u[0][2]=u[1][0]=u[2][1]=1;
    ans[0][0]=ans[1][1]=ans[2][2]=1;
    ll k=n-3;
	for(; k; k>>=1,mult(u,u))
		(k&1)&&(mult(u,ans),1);
    printf("%lld",quickpow(c,ans[0][0])*quickpow(b,ans[0][1])%mod*quickpow(a,ans[0][2])%mod*quickpow(d,(-n)%(mod-1)+(mod-1))%mod);
    return 0;
}