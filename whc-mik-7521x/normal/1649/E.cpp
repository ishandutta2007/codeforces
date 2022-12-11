#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10,mod=998244353;
long long fac[N],inv[N],inn[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
void init(){
    fac[0]=inv[0]=1;
    for(long long i=1;i<N;i++)inn[i]=fp(i,mod-2);
    for(long long i=1;i<N;i++)fac[i]=fac[i-1]*i%mod;
    inv[N-1]=fp(fac[N-1],mod-2);
    for(long long i=N-2;i>=1;i--){
        inv[i]=inv[i+1]*(i+1)%mod;
    }
}
long long C(long long x,long long y){
    return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
long long A(long long x,long long y){
    return fac[x]*inv[x-y]%mod;
}
struct BIT{
    long long ts[N];
    long long ask(long long x){
        x++;
        long long res=0;
        for(;x;x-=x&-x)res+=ts[x]+mod,res%=mod;
        return res;
    }
    void add(long long x,long long d){
        x++;
        for(;x<N;x+=x&-x)ts[x]+=d+mod,ts[x]%=mod;
    }
}tr;
long long n,m,cnt[N],s[N],t[N];
int main(){
    init();
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        cnt[x]++;
    }
    long long now=fac[n];
    for(long long i=1;i<N;i++){
        now=(now*inv[cnt[i]])%mod;
        tr.add(i,cnt[i]);
    }
    long long sum=n;
    for(long long i=1;i<=m;i++){
        scanf("%lld",&t[i]);
    }
    long long ans=0,pd=0;
    for(long long i=1;i<=min(n,m);i++){
        long long kk=now*inn[sum]%mod;
        ans+=kk*(tr.ask(t[i]-1))%mod;
        ans%=mod;
        now*=inn[sum];
        now%=mod;
        if(cnt[t[i]]){
            tr.add(t[i],-cnt[t[i]]);
            now*=cnt[t[i]];
            now%=mod;
            sum--;
            cnt[t[i]]--;
            tr.add(t[i],cnt[t[i]]);
        }
        else{
            pd=1;
            break;
        }
    }
    if(n<m&&!pd)ans++;
    ans%=mod;
    printf("%lld",ans);
    return  0;
}