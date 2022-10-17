#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
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
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        if(a[n - 1] == a[n - 2]) {
            cout << 0 << '\n';
            continue;
        }
        if(n == 2) {
            cout << 1 << '\n';
            continue;
        }
        a.pop_back();
        vector<mint> f(n + 1), rf(n + 1);
        f[0] = rf[0] = 1; for(int i = 1; i <= n; ++i) f[i] = i * f[i - 1], rf[i] = 1 / f[i];
        map<int, int> mp;
        for(int i : a) mp[i] += 1;
        vector<int> b;
        for(auto [x, y] : mp) b.push_back(y);
        vector<mint> dp(n + 1);
        dp[0] = 1;
        int pre = 0;
        for(int x : b) {
            vector<mint> ndp(n + 1);
            for(int i = 0; i <= n; ++i) {
                if(dp[i] == 0) continue;
                ndp[i + x] += dp[i] * rf[x];
                if(i == pre) {
                    if(i > 1) ndp[i - 2 + x - 1] += dp[i] * rf[x - 1] * i * (i - 1);
                } else {
                    if(i > 0) ndp[i - 1 + x - 1] += dp[i] * rf[x - 1] * i;
                }
            }
            dp = ndp;
            pre += x;
        }
        cout << dp[0] << '\n';
    }
}