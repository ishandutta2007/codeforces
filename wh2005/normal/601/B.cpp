#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,l,r;ll a[100009],h[100009];
ll absolute(ll x){return x<0?(-x):x;}
ll s[100009],top;
int main(){
    scanf("%lld%lld",&n,&m);
    for(ll i=1ll;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1ll;i<n;i++) h[i]=absolute(a[i+1]-a[i]);
    for(ll i=1ll;i<=m;i++){
        scanf("%lld%lld",&l,&r);top=0,s[0]=l-1;
        ll tmp=h[r],ans=0;h[r]=1e9;
        for(ll j=l;j<=r;j++){
            while(top&&h[j]>=h[s[top]]){
                ans+=(s[top]-s[top-1])*(j-s[top])*h[s[top]];
                top--;
            }
            s[++top]=j;
        }
        h[r]=tmp;
        printf("%lld\n",ans);
    }
    return 0;
}