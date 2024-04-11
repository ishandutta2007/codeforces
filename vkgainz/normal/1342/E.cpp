#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll fact[200001];
ll power(ll base, ll pow){
    if(pow==0) return 1;
    if(base==0) return 0;
    ll x = power(base,pow/2);
    if(pow%2){
        return ((((x*x%mod)*base%mod)+mod)%mod);
    }
    else{
        return ((x*x%mod)+mod)%mod;
    }
}
ll choose(int x,int y){
    if(y==0) return 1;
    ll a = fact[x];
    ll b = fact[y];
    ll c = fact[x-y];
    b = power(b,mod-2);
    c = power(c,mod-2);
    a = a*b;
    a%=mod;
    a = a*c;
    a%=mod;
    if(a<0) a+=mod;
    return a;
}
ll op(int a,int b){
    ll curr = 0;
    for(int i=0;i<=a;i++){
        ll x = choose(a,i);
        ll y = power(a-i,b);
        ll z = x*y%mod;
        if(i%2==0)
            curr+=z;
        else
            curr-=z;
    }
    curr%=mod;
    if(curr<0) curr+=mod;
    return curr;
}
int main(){
    int n;
    ll k;
    cin >> n >> k;
    fact[0] = 1;
    for(int i=1;i<=n;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
    }
    if(k>=n) {
        cout << 0 << endl;
        return 0;
    }
    if(k==0){
        cout << fact[n] << endl;
        return 0;
    }
    ll a = choose(n,k);
    //n-k, n
    ll b = op(n-k,n);
    ll c = a*b%mod;
    c*=2;
    c%=mod;
    if(c<0) c+=mod;
    cout << c << endl;

}