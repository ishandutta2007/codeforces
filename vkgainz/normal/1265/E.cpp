#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD = 998244353;
ll power(int base, int to){
    if(to==0){
        return 1;
    }
    ll x = power(base,to/2);
    ll ret;
    if(to%2==0){
        ret = x*x%MOD;
        ret%=MOD;
        if(ret<0) ret+=MOD;
        return ret;
    }
    else{
        ret = x*x%MOD;
        ret*=base;
        ret%=MOD;
        if(ret<0) ret+=MOD;
        return ret;
    }
        
            
}

int n;

int main(){
    cin >> n;
    ll p[n];
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    ll inverse = 1;
    for(int i=0;i<n;i++){
        ll mult = power(p[i],MOD-2);
        inverse*=mult;
        inverse%=MOD;
    }
    if(inverse<0) inverse+=MOD;
    ll pow100[n+1];
    pow100[1] = 100;
    for(int i=2;i<=n;i++){
        pow100[i] = pow100[i-1]*100;
        pow100[i]%=MOD;
        if(pow100[i]<0) pow100[i]+=MOD;

    }
    ll ans =pow100[n]*inverse;
    ans%=MOD;
    if(ans<0) ans+=MOD;
    for(int i=n-2;i>=0;i--){
        inverse*=p[n-i-2];
        inverse%=MOD;
        if(inverse<0) inverse+=MOD;
        ll temp = inverse*pow100[i+1]%MOD;
        
        temp%=MOD;
        ans+=temp;
        ans%=MOD;
        if(ans<0) ans+=MOD;
    }
    cout << ans << endl;

}