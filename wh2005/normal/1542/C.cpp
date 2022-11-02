#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll inf = 1e16;
const ll mod = 1e9+7;

int T;
ll n;

ll gcd(ll x,ll y){
    if(!y) return x;
    return gcd(y,x%y);
}

ll lcm(ll x,ll y){
    ll t=x/gcd(x,y);
    if(t>inf) return t;
    return t*y;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        ll p=1,ans=0;
        for(ll i=2;i<=100;i++){
            if(p>inf) break;
            ll n1=n/p;
            n1-=n/lcm(p,i);
            (ans+=n1%mod*i%mod)%=mod; 
            p=lcm(p,i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}