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
    int t;
    cin >> t;
    while(t--) {
        int n, m, sx, sy, tx, ty;
        mint p;
        cin >> n >> m >> sx >> sy >> tx >> ty >> p;
        p /= 100;
        --sx, --sy, --tx, --ty;
        int T = 2 * (n - 1) * (m - 1) / gcd(n - 1, m - 1);
        auto check = [&](int x, int y) {
            return x == tx || x + tx == 2 * (n - 1) || y == ty || y + ty == 2 * (m - 1);
        };
        vector<int> a;
        for(int i = 0; i < T; ++i) {
            int x = (sx + i) % (2 * (n - 1)), y = (sy + i) % (2 * (m - 1));
            if(check(x, y)) a.push_back(i);
        }
        int s = a.size();
        mint I = 0, J = 0, w = 1;
        for(int i = 0; i < a.size(); ++i) {
            I += a[i] * p * w;
            J += w * p;
            w = w * (1 - p);
        }
        mint ans = 1 / (1 - w) * I + T * J * w / (1 - w) / (1 - w);
        cout << ans << '\n';
    }
}