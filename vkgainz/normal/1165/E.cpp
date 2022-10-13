#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll a[200000];
ll n;
bool cmp(const ll &x,const ll &y){
    ll t1 = (x+1)*(n-x)*a[x];
    ll t2 = (y+1)*(n-y)*a[y];
    return t1<t2;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    ll b[n];
    for(int i=0;i<n;i++) cin >> b[i];
    sort(b,b+n);
    ll p[n];
    for(int i=0;i<n;i++){
        p[i] = i;
    }
    sort(p,p+n,cmp);
    map<ll,ll> idx;
    for(int i=0;i<n;i++){
        idx[p[i]] = b[n-i-1];
    }
    ll ans =0;
    for(int i=0;i<n;i++){
        ll temp = (ll) a[p[i]]*idx[p[i]];
        temp%=mod;
        temp*=(ll) (p[i]+1);
        temp%=mod;
        temp = (ll) temp*(n-p[i]);
        temp%=mod;
        ans+=temp;
        ans%=mod;
    }
    cout << ans << endl;
}