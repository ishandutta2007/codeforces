#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
int main(){
    int t; cin >> t;
    while(t--){
        ll k; scanf("%lld",&k);
        
        ll m = k/2;
        ll ans = (k+2)/2%mod;
        if(m%2==0){
            ans+=((m/2)%mod*1LL*((m/2)%mod))%mod;
        }
        else{
            ans+=((m/2)%mod*1LL*((m/2+1)%mod))%mod;
        }
        ans%=mod;
        if(ans<0) ans+=mod;
        printf("%lld\n",ans);
    }
}