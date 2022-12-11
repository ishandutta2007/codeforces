#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,N=1e4+10;
int t,n;
int ans[100000];
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
int main(){
    init();
	scanf("%d",&t);
	for(int i=2;i<=1000;i+=2)ans[i]=fac[i>>1]*fac[i>>1]%mod;
	while(t--){
		scanf("%d",&n);
        printf("%d\n",ans[n]);
	}
	return 0;
}