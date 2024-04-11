#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2009;
const int mod = 1e9+7;
int n,a[N],vis[N],num,tp[N],blk;
ll fac[N],inv[N];
ll C(int x,int y){
    return fac[y]*inv[x]%mod*inv[y-x]%mod;
}
int main(){
    memset(tp,0,sizeof(tp));
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);fac[0]=1,num=n,blk=0,inv[0]=inv[1]=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
    for(int i=2;i<=n;i++) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    for(int i=1;i<=n;i++) inv[i]=inv[i]*inv[i-1]%mod;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){blk++;continue;}
        if(tp[a[i]]){printf("0\n");return 0;}tp[a[i]]++;
        if(!vis[a[i]]) vis[a[i]]=1,num--;
        if(!vis[i]) vis[i]=1,num--;
    }
    ll ans=fac[blk];
    for(int i=1;i<=num;i++){
        ll k=(i&1)?(-1):1;
        ans+=(k*C(i,num)*fac[blk-i]%mod);
        ans=(ans%mod+mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}