#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 3;
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
vector<int> gauss(vector<vector<T>> &a) {
    int n = a.size(), m = a[0].size() - 1; // n * (m + 1)
    vector<int> id(m, -1);
    int p = 0;
    for(int i = 0; i < m; ++i) {
        for(int j = p; j < n; ++j) {
            if(a[j][i] != 0) {
                swap(a[j], a[p]);
                break;
            }
        }
        if(a[p][i] == 0) {
            id[i] = -1;
        } else {
            auto inv = 1 / a[p][i];
            for(int k = i; k <= m; ++k) {
                a[p][k] *= inv;
            }
            id[i] = p;
            for(int j = 0; j < n; ++j) {
                if(p != j && a[j][i] != 0) {
                    T tmp = a[j][i];
                    for(int k = p; k <= m; ++k) {
                        a[j][k] -= a[p][k] * tmp;
                    }
                }
            }
            p++;
            if(p == n) break;
        }
    }
    for(int i = p; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(a[i][j] != 0) {
                int k = id[j];
                assert(k != -1 && a[k][j] == 1);
                a[i][j] -= a[k][j];
                a[i][m] -= a[k][m];
            }
        }
        if(a[i][m] != 0) return vector<int>();
    }
    vector<int> ret(m);
    for(int i = 0; i < m; ++i) {
        if(id[i] != -1) ret[i] = a[id[i]][m].x;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int,int,int>> es(m);
        vector<vector<pair<int,int>>> g(n, vector<pair<int,int>>(n, {-1, -1}));
        vector<vector<mint>> a(1, vector<mint>(m + 1));
        int c = 0;
        for(auto &[u, v, w] : es) {
            cin >> u >> v >> w;
            --u, --v;
            if(w != -1) {
                w -= 1;
                vector<mint> b(m + 1);
                b[c] = 1;
                b[m] = w;
                a.push_back(b);
            }
            if(u > v) swap(u, v);
            g[u][v] = {w, c};
            ++c;
        }
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                for(int k = j + 1; k < n; ++k) {
                    if(g[i][j].second != -1 && g[i][k].second != -1 && g[j][k].second != -1) {
                        vector<mint> b(m + 1);
                        b[g[i][j].second] = 1;
                        b[g[i][k].second] = 1;
                        b[g[j][k].second] = 1;
                        a.push_back(b);
                    }
                }
            }
        }
        vector<int> ret = gauss(a);
        if(ret.empty()) cout << -1 << '\n';
        else {
            for(int i : ret) cout << i + 1 << " ";
            cout << '\n';
        }
    }
}