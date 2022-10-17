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
    mint operator -() {return mint(-x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}
vector<mint> f(1,1), rf(1,1);
mint comb(int n,int k) {
    if(n<k||k<0)return 0;
    return f[n]*rf[k]*rf[n-k];
}

template<typename T>
struct fenwick {
    vector<T> a;
    int n;
    fenwick(int n): n(n), a(n) {}
    void add(int x, T v) {
        assert(0 <= x && x < n);
        for(int i = x + 1; i <= n; i += i & -i) a[i - 1] += v;
    }
    T qry(int x) {
        T ret = 0;
        for(int i = min(x + 1, n); i > 0; i -= i & -i) ret += a[i - 1];
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
    for(int i = 0; i < m; ++i) cin >> b[i], --b[i];
    const int N = 2e5 + 5;
    fenwick<int> fen(N);
    for(int i : a) fen.add(i, 1);
    vector<int> ca(N);
    f.resize(N), rf.resize(N);
    for(int i = 1; i < N; ++i) f[i] = f[i - 1] * i; rf[N - 1] = 1 / f[N - 1];
    for(int i = N - 2; i >= 0; --i) rf[i] = rf[i + 1] * (i + 1);
    mint cur = f[n];
    for(int i : a) ca[i]++;
    for(int i = 0; i < N; ++i) cur *= rf[ca[i]];
    mint ans = 0;
    for(int i = 0; i < n; ++i) {
        if(i == m) break;
        ans += cur / (n - i) * fen.qry(b[i] - 1);
        cur /= (n - i);
        if(ca[b[i]]) {
            cur *= f[ca[b[i]]];
            --ca[b[i]];
            cur *= rf[ca[b[i]]];
            fen.add(b[i], -1);
        } else {
            break;
        }
        if(i + 1 == n && m > n) ans += 1;
    }
    cout << ans << '\n';
}