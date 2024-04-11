#include <bits/stdc++.h>
using namespace std;
#define ll long long

int m,d,w;
void solve(){
    int gcd = __gcd(d-1,w);
    w/=gcd;
    ll div = min(d,m)/w;
    ll mod = min(d,m)%w;
    ll ans =0;
    if(mod){
        ans = mod*(div+1)*div/2;
        ans+=(w-mod)*div*(div-1)/2;
    }
    else{
        ans = w*div*(div-1)/2;
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> m >> d >> w;
        solve();
    }
}