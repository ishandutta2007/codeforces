#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll mod = 1e9+7;
const int N = 1e5+9;
int pri[N],f[N],tot;
void init(){
    f[1]=1,tot=0;
    for(int i=2;i<=N-9;i++){
        if(!f[i]) pri[++tot]=i;
        for(int j=1;j<=tot&&pri[j]*i<=N-9;j++){
            f[pri[j]*i]=1;if(i%pri[j]==0) break;
        }
    }
    return ;
}
ll getmu(int x){
    int cnt=0;
    for(int i=1;i<=tot&&1ll*pri[i]*pri[i]<=x;i++)
        if(x%pri[i]==0){
            int t=0;while(x%pri[i]==0) x/=pri[i],t++;
            if(t>1) return 0;cnt^=1;
        }
    if(x>1) cnt^=1; 
    return cnt?(mod-1ll):1ll;
}
ll qpow(ll x,ll y){
    ll t=1;while(y){if(y&1) (t*=x)%=mod;(x*=x)%=mod,y>>=1;}
    return t;
}

int main(){
    init();
    int x,y;scanf("%d%d",&x,&y);
    if(y%x){printf("0\n");return 0;}
    int n=y/x;ll ans=0;
    for(int i=1;1ll*i*i<=n;i++)
        if(n%i==0){
            (ans+=getmu(n/i)*qpow(2,i-1)%mod)%=mod;
            if(n/i!=i) (ans+=getmu(i)*qpow(2,n/i-1)%mod)%=mod;
        }
    printf("%lld\n",ans);
    return 0;
}
/*
g++ CF900D2.cpp -o A
*/