#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;
    ll x;
    scanf("%i %lld",&n,&x);
    ll a[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    ll ans=x;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            ans=max(ans,a[j]*(x/a[i])+x%a[i]);
        }
    }
    printf("%lld",ans);
    return 0;
}