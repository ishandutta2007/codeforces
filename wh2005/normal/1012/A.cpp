#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e6+9;
int n;
ll a[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n*2;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n*2+1);
    ll ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
    for(int i=n+1;i<n*2;i++){
        ll y=(a[i]-a[1])*(a[n*2]-a[n]);
        ans=min(ans,y);
    }
    for(int i=2;i<=n;i++){
        ans=min(ans,(a[n*2]-a[1])*(a[i+n-1]-a[i]));
    }
    printf("%lld\n",ans);
    return 0;
}
/*
 2n  2  n 
*/