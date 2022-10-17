#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll inv(ll a) {ll u=0,v=1,b=mod;while(a) {ll t=b/a;b-=t*a,u-=t*v;swap(a,b);swap(u,v);}u%=mod;if(u<0)u+=mod;return u;}
struct mint {
    int x;
    mint():x(0) {}
    mint(int x):x(x) {if(x>=mod||x<-mod)x%=mod;if(x<0)x+=mod;this->x=x;}
    mint(ll x):x() {if(x>=mod||x<-mod)x%=mod;if(x<0)x+=mod;this->x=x;}
    mint& operator -=(const mint &rhs) {x -= rhs.x; if(x < 0) x += mod; return *this;}
    mint& operator +=(const mint &rhs) {x += rhs.x; if(x >= mod) x -= mod; return *this;}
    mint& operator *=(const mint &rhs) {x = (ll)x * rhs.x % mod; return *this;}
    mint& operator /=(const mint &rhs) {x = (ll)x * inv(rhs.x) % mod; return *this;}
    bool operator < (const mint& rhs) {return x < rhs.x;}
    bool operator == (const mint& rhs) {return x == rhs.x;}
    bool operator != (const mint& rhs) {return x != rhs.x;}
    mint operator -() {return mint(x == 0 ? 0 : mod - x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    vector<mint> f(p + 1);
    f[0] = f[1] = 1;
    for(int i = 2; i <= p; ++i) f[i] = f[i - 1] + f[i - 2];
    for(int i = 1; i <= p; ++i) f[i] += f[i - 1];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    set<int> vis;
    mint ans = 0;
    for(int i = 0; i < n; ++i) {
        int x = a[i], ok = 1, len = 32 - __builtin_clz(a[i]);
        if(len > p) continue;
        while(x) {
            if(x & 1) x /= 2;
            else if(x % 4 == 0) x /= 4;
            else break;
            if(vis.count(x)) {
                ok = 0;
            }
        }
        if(ok) {
            vis.insert(a[i]);
            ans += f[p - len];
        }
    }
    cout << ans << '\n';
}