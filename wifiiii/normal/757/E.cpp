#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;
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
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> mp(maxn), np(maxn), f(maxn);
    np[1] = mp[1] = 1; f[1] = 0;
    for(int i = 2; i < maxn; ++i) {
        if(np[i]) continue; mp[i] = i; f[i] = 1;
        for(int j = i + i; j < maxn; j += i) {
            np[j] = 1;
            if(!mp[j]) mp[j] = i;
            f[j] += 1;
        }
    }
    for(int i = 0; i < maxn; ++i) f[i] = 1 << f[i];
    vector<vector<int>> e(maxn);
    e[1].push_back(0);
    for(int i = 1; i < maxn; ++i) {
        int x = i;
        while(x != 1) {
            int p = mp[x], cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt += 1;
            }
            e[i].push_back(cnt);
        }
        if(x > 1) e[i].push_back(1);
    }
    int t;
    cin >> t;
    while(t--) {
        int r, n;
        cin >> r >> n;
        if(r == 0) cout << f[n] << '\n';
        else {
            mint ans = 1;
            for(int i : e[n]) {
                mint tmp = 0;
                for(int j = 0; j <= i; ++j) {
                    tmp += comb(r - 1 + j, r - 1) * (1 << (j < i));
                }
                ans *= tmp;
            }
            cout << ans << '\n';
        }
    }
}