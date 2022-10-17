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
// 0 <= x < n

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        vector<int> ord(n);
        iota(ord.begin(), ord.end(), 0);
        sort(ord.begin(), ord.end(), [&](int i, int j) {return a[i] < a[j] || (a[i] == a[j] && i > j);});
        for(int i = 0; i < n; ++i) a[ord[i]] = i;

        int mx = -1;
        vector<int> suf;
        for(int i = n - 1; i >= 0; --i) {
            if(a[i] > mx) {
                mx = a[i];
                suf.push_back(a[i]);
            }
        }
        sort(suf.begin(), suf.end());
        
        fenwick<mint> fenl(n), fenr(n); vector<mint> dpl(n), dpr(n);
        for(int i = 0; i < n; ++i) {
            dpl[i] = fenl.qry(a[i] - 1) + 1;
            fenl.add(a[i], dpl[i]);
        }
        for(int i = n - 1; i >= 0; --i) {
            dpr[i] = fenr.qry(n - 1) - fenr.qry(a[i]) + 1;
            fenr.add(a[i], dpr[i]);
        }
        mint ans = 0;
        for(int i = 0; i < n; ++i) {
            int p = *lower_bound(suf.begin(), suf.end(), a[i]);
            if(a[i] < p) ans += dpl[i] * dpr[i];
        }
        vector<vector<int>> b(n);
        fenwick<mint> qwq(n);
        for(int i = 0; i < n; ++i) {
            int pos = ord[*lower_bound(suf.begin(), suf.end(), a[i])];
            if(i != pos) {
                b[pos].push_back(i);
            } else {
                vector<pair<int,mint>> mem;
                for(int j : b[i]) {
                    mint tmp = qwq.qry(a[j] - 1) + dpl[j];
                    qwq.add(a[j], tmp);
                    mem.push_back({a[j], tmp});
                }
                ans -= qwq.qry(a[i]);
                for(auto [x, y] : mem) {
                    qwq.add(x, -y);
                }
            }
        }
        cout << ans << '\n';
    }
}