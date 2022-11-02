#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll T,n;

int main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        ll p=sqrt(n),ans=1e9;
        for(ll i=max(p-20ll,1ll);i<=min(p+20ll,n);i++){
            ll x=(long long)ceil((1.0*n)/(1.0*i));
            ans=min(ans,i+x-1);
        }
        printf("%lld\n",ans-1);
    }
    return 0;
}