#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll test[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
ll mul(ll a,ll b,ll mod) {ll tmp=(long double)a*b/mod;return ((a*b-tmp*mod)%mod+mod)%mod;}
ll fpow(ll a,ll b,ll mod){ll r=1;for(a%=mod;b;b>>=1){if(b&1)r=mul(r,a,mod);a=mul(a,a,mod);}return r;}
ll gcd(ll a,ll b) {return b==0?a:gcd(b,a%b);}
int isp(ll n) {
    if(n <= 2) return n == 2;
    ll t = n-1, k = 0;
    while(!(t&1)) t>>=1,++k;
    for(int i=0;i<3;++i) {
        if(n==test[i]) return 1;
        ll a=fpow(test[i],t,n),nxt=a;
        for(int j=1;j<=k;++j) {
            nxt=mul(a,a,n);
            if(nxt==1 && a!=1 && a!=n-1) return 0;
            a=nxt;
        }
        if(a!=1) return 0;
    }
    return 1;
}
ll work(ll n, int beta, int c) {
    if(n % 2 == 0) return 2;
    ll x = 2, y = 2, d = 1;
    while(1) {
        ll tx = x, ty = y;
        for(int i=1;i<=beta;++i) {
            x=mul(x,x,n)+c;if(x>=n) x-=n;
            y=mul(y,y,n)+c;if(y>=n) y-=n;
            y=mul(y,y,n)+c;if(y>=n) y-=n;
            d=mul(d,x-y+n,n);
        }
        d=gcd(d,n);
        if(d == 1) continue;
        if(d != n) return d;
        for(int i=1;i<=beta;++i) {
            x=mul(x,x,n)+c;if(x>=n) x-=n;
            y=mul(y,y,n)+c;if(y>=n) y-=n;
            y=mul(y,y,n)+c;if(y>=n) y-=n;
            d=gcd(d,x-y+n);
            if(d != 1) return d % n;
        }
        return 0;
    }
}
void solve(ll n, vector<ll>&vec) {
    if(isp(n) || n==1) {vec.push_back(n);return;}
    int beta = pow(n, 0.1), c = 1;
    ll tmp = 0;
    while(!tmp) tmp = work(n, beta, c++);
    solve(tmp, vec);
    solve(n/tmp, vec);
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> d;
        solve(n, d);
        sort(d.begin(), d.end());
        ll x = d[0], y = 1, z = 1;
        int f = 0;
        for(int i = 1; i < d.size(); ++i) {
            if(f) {
                z *= d[i];
            } else {
                y *= d[i];
                if(y != x) f = 1;
            }
        }
        if(x != 1 && y != 1 && z != 1 && x != y && y != z && x != z) cout << "YES\n" << x << " " << y << " " << z << endl;
        else cout << "NO" << endl;
    }
}