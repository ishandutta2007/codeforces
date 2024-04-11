#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll fact[1000];
vector<ll> primes;
ll inv(ll b,ll p){
    if(b==1) return 1;
    if(p==0) return 1;
    ll x = inv(b,p/2);
    if(p%2==1){
        return ((x*x%mod*b)%mod+mod)%mod;
    }
    else{
        return ((x*x%mod)+mod)%mod;
    }
}
void factor(ll x){
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            primes.push_back(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x>1) primes.push_back(x);
}
int main(){
    ll d; cin >> d;
    factor(d);
    fact[0] = 1;
    for(int i=1;i<1000;i++){
        fact[i] = fact[i-1]*i;
        fact[i]%=mod;
        if(fact[i]<0) fact[i]+=mod;
    }
    int q; cin >> q;
    while(q--){
        ll v,u;
        cin >> v >> u;
        ll gcd = __gcd(v,u);
        v/=gcd;
        u/=gcd;
        ll sum1 = 0;
        ll sum2=0;
        ll prod1 = 1;
        ll prod2 = 1;
        for(ll p : primes){
            int f =0;
            while(v%p==0){
                ++sum1;
                ++f;
                v/=p;
            }
            prod1*=fact[f];
            prod1%=mod;
        }
        sum1 = fact[sum1];
        for(ll p : primes){
            int f =0;
            while(u%p==0){
                ++sum2;
                ++f;
                u/=p;
            }
            prod2*=fact[f];
            prod2%=mod;
        }
        sum2 = fact[sum2];
        sum1*=inv(prod1,mod-2);
        sum1%=mod;
        sum2*=inv(prod2,mod-2);
        sum2%=mod;
        sum1*=sum2;
        sum1%=mod;
        if(sum1<0) sum1+=mod;
        cout << sum1 << endl;
        
        
    }
}