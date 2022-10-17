#include "bits/stdc++.h"

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n));
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(s[i] != s[j]) {
                if(s[i] == '?' || s[j] == '?') {
                    int x = (s[i] ^ s[j] ^ '?') - 'a';
                    a[i][j] = 1 << x;
                    //D(i, j);
                } else {
                    a[i][j] = 1 << 18;
                }
            }
            if(s[i] == '?' || s[j] == '?') b[i][j] = 1;
        }
    }
    int tot = 0;
    for(char c : s) if(c == '?') tot += 1;
    for(int i = 0; i < n; ++i) {
        for(int j = i - 1; j >= 0; --j) {
            if(j >= 1 && i + 1 < n) {
                a[j - 1][i + 1] |= a[j][i];
                b[j - 1][i + 1] += b[j][i];
            }
        }
    }
    vector<vector<mint>> dp(18, vector<mint>(1 << 17));
    for(int k = 1; k <= 17; ++k) {
        vector<mint> pw(n + 1, 1);
        for(int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * k;
        for(int i = 0; i < n; ++i) {
            for(int j = i; j < n; ++j) {
                if(a[i][j] >> 18 & 1) continue;
                dp[k][a[i][j]] += pw[tot - b[i][j]];
            }
        }
        for(int i = 0; i < 17; ++i) {
            for(int j = 0; j < 1 << 17; ++j) {
                if(j >> i & 1) dp[k][j] += dp[k][j ^ (1 << i)];
            }
        }
    }


    int q;
    cin >> q;
    for(int i = 0; i < q; ++i) {
        int x = 0;
        string s;
        cin >> s;
        for(char c : s) {
            x |= 1 << (c - 'a');
        }
        cout << dp[s.size()][x] << '\n';
    }
}