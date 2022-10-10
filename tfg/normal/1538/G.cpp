#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        ll x,y,a,b;
        cin>>x>>y>>a>>b;
        
        if(a > b){
            swap(a,b);
            swap(x,y);
        }
        auto check = [&](ll k){
            if(a == b){
                return a*k <= min(x,y);
            }else{
                // b > a
                // k1 * (a - b) <= x - k*b
                // k1 * (b - a) <= y - k*a
                ll k1 = (y-k*a)/(b-a);
                k1 = min(k1, k);
                return k1 * (a - b) <= x - k * b && k1 >= 0 && k1 * (b - a) <= y - k * a;
            }
        };
        
        ll lo = 0 , hi = 1e9;
        ll ans = 0;
        while(lo<=hi){
            ll m = (lo+hi)/2;
            if(check(m)){
                ans = m;
                lo = m+1;
            }else{
                hi = m-1;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}