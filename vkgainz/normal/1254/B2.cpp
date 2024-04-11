#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000001];
ll s[1000001];
set<ll> primes(ll x){
    set<ll> ret;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0){
            ret.insert(i);
            while(x%i==0){
                x/=i;
            }
        }
    }
    if(x>1) ret.insert(x);
    return ret;
}
ll best = 1000000000000000000;
int n;
ll num(ll k){
    ll ret = 0;
    for(int i=0;i<n-1;i++){
        ret+=min(s[i]%k,k-s[i]%k);
    }
    return ret;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    ll sum = 0;
    for(int i=0;i<n;i++) sum+=a[i];
    set<ll> primeSet = primes(sum);
    s[0] = a[0];
    for(int i=1;i<n;i++)s[i] = a[i]*1LL+s[i-1];
    for(ll temp : primeSet){
        best = min(best,num(temp));
    }
    if(best==1000000000000000000){
        cout << -1 << endl;
    }
    else{
        cout << best << endl;
    }
}