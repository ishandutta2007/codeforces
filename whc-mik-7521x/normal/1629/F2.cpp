#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+7;
long long jc[N],jcny[N],pw[N],pwny[N];
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
long long C(long long x,long long y){
    return jc[x]*jcny[y]%mod*jcny[x-y]%mod;
}
int main(){
    jc[0]=1;
    for(int i=1;i<N;i++)jc[i]=jc[i-1]*i%mod;
    for(int i=0;i<N;i++)jcny[i]=fp(jc[i],mod-2);
    pw[0]=1;
    for(int i=1;i<N;i++)pw[i]=pw[i-1]*2%mod;
    for(int i=0;i<N;i++)pwny[i]=fp(pw[i],mod-2);
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        if(n==m){printf("%lld\n",1ll*k*n%mod);continue;}
        long long ans=0;
        for(int i=1;i<=m;i++){
            ans+=1ll*k*i%mod*C(n-i-1,m-i)%mod*pwny[n-i]%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return  0;
}