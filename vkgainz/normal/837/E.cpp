#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
ll gcd(ll x, ll y) {
    if(y==0) return x;
    return gcd(y,x%y);
}
int main() {
    ll x,y; cin >> x >> y;
    map<ll, int> pf;
    ll t = x;
    for(ll i=2;i*1LL*i<=x;i++) {
        if(x%i==0) {
            while(x%i==0) {
                ++pf[i];
                x/=i;
            }
        }
    }
    if(x>1) ++pf[x];
    x = t;
    ll ans = 0;
    ll g = gcd(x,y);
    x/=g, y/=g;
    while(y>0 && x>1) {
        ll mn = 1e12;
        for(auto &it : pf) {
            if(x%it.f==0) {
                mn = min(mn,y%it.f);
            }
        }
        ans+=mn;
        y-=mn;
        g = gcd(x,y);
        x/=g, y/=g;
    }
    if(x==1) ans+=y;
    cout << ans << endl;
}