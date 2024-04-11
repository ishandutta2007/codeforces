#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int T;
ll p,a,b,c;
ll calc(ll x,ll p){
    if(p%x==0) return 0;
    return (p/x+1ll)*x-p;
}

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
        ll ans=calc(a,p);
        ans=min(ans,calc(b,p));
        ans=min(ans,calc(c,p));
        printf("%lld\n",ans);
    }
    return 0;
}