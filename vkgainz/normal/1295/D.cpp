#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll phi(ll n){
    ll prod = 1;
    for(ll i=2;i<=sqrt(n);i++){
        if(n%i==0){
            ll fac = 0;
            while(n%i==0){
                n/=i;
                fac++;
            }
            prod*=(i-1);
            prod*=pow(i,fac-1);
        }
    }
    if(n!=1) prod*=(n-1);
    return prod;
}
int main(){
    int T;cin >> T;
    while(T--){
        ll a,m;
        cin >> a >> m;
        int gcd = __gcd(a,m);
        m/=gcd;
        cout << phi(m) << endl;
    }
}