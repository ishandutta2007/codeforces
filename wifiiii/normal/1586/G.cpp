#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
//const int mod = 998244353;
ll inv(ll a) {ll u=0,v=1,b=mod;while(a) {ll t=b/a;b-=t*a,u-=t*v;swap(a,b);swap(u,v);}u%=mod;if(u<0)u+=mod;return u;}
struct mint {
    int x;
    mint():x(0) {}
    mint(int x):x(x) {} // 0 <= x < mod
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
    int n;
    cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
    }
    vector<int> ord(n), rord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i].second < a[j].second;});
    sort(a.begin(), a.end(), [&](auto i, auto j) {return i.second < j.second;});
    for(int i = 0; i < n; ++i) rord[ord[i]] = i;
    int m;
    cin >> m;
    vector<int> b(m);
    for(int i = 0; i < m; ++i) {
        cin >> b[i];
        b[i] = rord[b[i] - 1];
    }
    sort(b.begin(), b.end());
    vector<int> qry(n, -1);
    int lst = a[b[m - 1]].first;
    for(int i = m - 2; i >= 0; --i) {
        auto [l, r] = a[b[i]];
        if(lst > l) continue;
        qry[b[i]] = lst;
        lst = l;
    }
    vector<mint> dp1(n), dp2(n), dp3(n);
    fenwick<mint> fen(2 * n);
    auto cmp = [&](pair<int,int> i, pair<int,int> j) {
        return i.second < j.second;
    };
    mint ans = 0;
    for(int i = 0; i < n; ++i) {
        auto [l, r] = a[i];
        if(i > 0) {
            dp1[i] = dp1[i - 1] + dp2[i - 1];
            dp2[i] = fen.qry(2 * n - 1) - fen.qry(l) + 1;
        } else {
            dp2[i] = 1;
        }
        if(qry[i] != -1) {
            ans += fen.qry(2 * n - 1) - fen.qry(qry[i]) + 1;
        }
        fen.add(l, dp2[i]);
    }
    ans += dp1[b[m - 1]] + 1;
    cout << ans << '\n';
}