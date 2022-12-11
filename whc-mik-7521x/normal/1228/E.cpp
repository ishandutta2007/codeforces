#include<bits/stdc++.h>
const int N=1e6+10,mod=1e9+7;
using namespace std;
int n,k,ans;
long long fac[N],inv[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(int i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
//long long Lucas(long long n,long long m,long long mod){
//	if(!m)return 1;
//	return Lucas(n/mod,m/mod,mod)*C(n%mod,m%mod,mod)%mod;
//}
int main(){
    init();
    scanf("%d%d",&n,&k);
	if(k==1)return puts("1"),0;
	for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int res=1ll*C(n,i)*C(n,j)%mod*fp(k-1,1ll*n*n-1ll*(n-i)*(n-j))%mod*fp(k,1ll*(n-i)*(n-j))%mod;
            if((i+j)&1)ans=(ans-res+mod)%mod;
            else ans=(ans+res)%mod;
        }
    }
	printf("%d\n",ans);
}