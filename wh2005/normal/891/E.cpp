#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 5e3+9;
int n,k;
ll a[N],c[2][N];
ll qpow(ll x,ll y){
    ll t=1;while(y){if(y&1) (t*=x)%=mod;y>>=1,(x*=x)%=mod;}
    return t;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    c[0][0]=1;
    ll sum=1;
    for(int i=1;i<=n;i++){
        int V=i&1;
        memset(c[V],0,sizeof(c[V]));
        for(int j=0;j<n;j++) c[V][j+1]=((c[V][j+1]-c[V^1][j])%mod+mod)%mod;
        for(int j=0;j<=n;j++) (c[V][j]+=c[V^1][j]*a[i]%mod)%=mod;
        (sum*=a[i])%=mod;
    }
    int p=n&1;
    ll ans=0,mi=1;
    for(int i=0;i<=n;i++){
        (ans+=c[p][i]*mi%mod*qpow(qpow(n,i),mod-2)%mod)%=mod;
        (mi*=(ll)(k-i))%=mod;
    }
    printf("%lld\n",((sum-ans)%mod+mod)%mod);
    return 0;
}