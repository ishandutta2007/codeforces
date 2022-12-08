#include<bits/stdc++.h>
using namespace std;
const int N = 2111111;
typedef long long ll;
const ll mod = 1e9+7;
ll x,n;
ll a[N];
ll pw(ll a,ll b){
    b%=mod-1;
    ll an=1;
    for(;b;b>>=1){
        if(b&1)an=an*a%mod;
        a=a*a%mod;
    }
    return an;
}
int main() {
    cin>>x>>n;
    int cnt=0;
    ll xx=x;
    for (int i=2;i*i<=xx;++i)if(x%i==0){
        while(x%i==0)x/=i;
        a[++cnt]=i;
    }
    ll ans=1;
    if(x>1)a[++cnt]=x;
    for(int i=1;i<=cnt;++i){
        // cout<<i<<" "<<a[i]<<endl;
        ll t=n;
        ll p=a[i]; 
        ll tmp=0;
        while(t){
            (tmp+=t/p)%=mod-1;
            t/=p;
        }
        ans=ans*pw(p,tmp)%mod;
    }
    cout<<ans<<endl;
    return 0;
}