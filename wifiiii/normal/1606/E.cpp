#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 998244353;
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
mint dp[505][505], pw[505][505];

int main() {
    int n, k;
    cin >> n >> k;
    for(int j=0;j<=k;++j) dp[0][j]=1,dp[2][j]=j;
    for(int i=1;i<=n;++i) {
        pw[i][0]=1;
        for(int j=1;j<=n;++j) {
            pw[i][j]=pw[i][j-1]*i;
        }
    }
    for(int i=3;i<=n;++i) {
        for(int j=1;j<=k;++j) {
            if(j<i) {
                dp[i][j]=fpow(j,i);
            } else {
                mint tmp=0;
                for(int p=0;p<=i;++p) {
                    tmp+=comb(i,p)*pw[i-1][p]*dp[i-p][j-i+1];
                }
                dp[i][j]=tmp;
            }
        }
    }
    cout<<dp[n][k]<<endl;
}