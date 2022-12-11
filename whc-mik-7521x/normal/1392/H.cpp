#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10,mod=998244353;
int n,m;
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
int main(){
    scanf("%d%d",&n,&m);
    long long sum=0;
    for(int i=1;i<=n;i++)(sum+=fp(i,mod-2))%=mod;
    printf("%lld",(n+m+1ll)*(m*sum%mod+1)%mod*fp(m+1,mod-2)%mod);
    return 0;
}