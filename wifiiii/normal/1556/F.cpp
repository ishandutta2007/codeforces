#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
ll inv(ll a) {ll u=0,v=1,b=mod;while(a) {ll t=b/a;b-=t*a,u-=t*v;swap(a,b);swap(u,v);}u%=mod;if(u<0)u+=mod;return u;}
struct mint {
    int x;
    mint():x(0) {}
    mint(int x):x(x) {}
    mint(ll x):x() {if(x>=mod||x<-mod)x%=mod;if(x<0)x+=mod;this->x=x;}
    mint& operator -=(const mint &rhs) {x -= rhs.x; if(x < 0) x += mod; return *this;}
    mint& operator +=(const mint &rhs) {x += rhs.x; if(x >= mod) x -= mod; return *this;}
    mint& operator *=(const mint &rhs) {x = (ll)x * rhs.x % mod; return *this;}
    mint& operator /=(const mint &rhs) {x = (ll)x * inv(rhs.x) % mod; return *this;}
    bool operator < (const mint& rhs) {return x < rhs.x;}
    bool operator == (const mint& rhs) {return x == rhs.x;}
    bool operator != (const mint& rhs) {return x != rhs.x;}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}

//mint comb(int n,int k) {
//    if(n<k||k<0)return 0;
//    static vector<mint> f(1,1), rf(1,1);
//    int p=f.size();
//    if(p<n) f.resize(n+1),rf.resize(n+1);
//    for(int i=p;i<=n;++i) f[i]=f[i-1]*i;rf[n]=1/f[n];
//    for(int i=n-1;i>=p;--i) rf[i]=rf[i+1]*(i+1);
//    return f[n]*rf[k]*rf[n-k];
//}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<mint> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<mint>> win(n, vector<mint>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            win[i][j] = a[i] * fpow(a[i] + a[j], mod - 2);
        }
    }
    vector<mint> dp(1 << n);
    for(int i = 1; i < 1 << n; ++i) {
        dp[i] = 1;
        for(int j = (i - 1) & i; j; j = (j - 1) & i) {
            mint tmp = 1;
            for(int k = 0; k < n; ++k) {
                if((i >> k & 1) && (j >> k & 1))
                    for(int p = 0; p < n; ++p) {
                        if((i >> p & 1) && !(j >> p & 1)) {
                            tmp = tmp * win[k][p];
                        }
                    }
            }
            dp[i] -= dp[j] * tmp;
        }
    }
    mint ans = 0;
    for(int i = 1; i < 1 << n; ++i) {
        mint tmp = 1;
        for(int j = 0; j < n; ++j) {
            if(i >> j & 1)
                for(int k = 0; k < n; ++k) {
                    if(!(i >> k & 1))
                        tmp = tmp * win[j][k];
                }
        }
        ans += tmp * dp[i] * __builtin_popcount(i);
    }
    cout << ans << '\n';
}