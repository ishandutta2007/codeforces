#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;

int main(){
    ll n; scanf("%lld",&n);
    ll h[n]; 
    ll sum =0;
    for(int i=0;i<n;i++){
        scanf("%lld",&h[i]);
        sum+=h[i];
    }
    if((sum*2)%n==0 && (ll)((sum*2)/n+1-n) %2==0){
        ll posStart = ((ll) (sum*2)/n+1-n)/2;
        for(int i=0;i<n;i++){
            printf("%lld ", posStart+i);
        }
    }
    else{
        ll posStart = (ll) (2*sum-(n-1)*(n-2))/(2*n);
        ll rep = sum-(ll) (2*posStart+n-2)*(n-1)/2;
        for(int i=0;i<n-1;i++){
            printf("%lld ", posStart+i);
            if(posStart+i==rep){
                printf("%lld ", rep);
            }
        }
    }
}