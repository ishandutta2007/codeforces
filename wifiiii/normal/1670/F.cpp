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
    mint operator -() {return mint(-x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}
mint comb(int n,int k) {
    if(n<k||k<0)return 0;
    static vector<mint> f(1,1), rf(1,1);
    if(f.size()<=n) {
        int p=f.size();
        f.resize(n+1),rf.resize(n+1);
        for(int i=p;i<=n;++i) f[i]=f[i-1]*i;rf[n]=1/f[n];
        for(int i=n-1;i>=p;--i) rf[i]=rf[i+1]*(i+1);
    }
    return f[n]*rf[k]*rf[n-k];
}

const int B = 60;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; ll l, r, z;
    cin >> n >> l >> r >> z;
    auto solve = [&](int n, ll x, ll z) -> mint {
        vector<int> a;
        for(int i = 0; i < B; ++i) {
            a.push_back(x % 2);
            x /= 2;
        }
        vector<mint> dp(2 * n + 1);
        dp[0] = 1;
        for(int k = B - 1; k >= 0; --k) {
            vector<mint> ndp(2 * n + 1);
            for(int i = 0; i <= 2 * n; ++i) {
                if(dp[i] == 0) continue;
                for(int j = (z >> k & 1); j <= n && a[k] + i >= j; j += 2) {
                    ndp[min(2 * n, 2 * (a[k] + i - j))] += comb(n, j) * dp[i];
                }
            }
            dp = ndp;
        }
        mint sum = 0;
        for(int i = 0; i <= 2 * n; ++i) sum += dp[i];
        return sum;
    };
    cout << solve(n, r, z) - solve(n, l - 1, z) << '\n';
}