#include <bits/stdc++.h>
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
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}
const int N = 1e6 + 5;
mint pw[N];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    pw[0] = 1;
    for(int i = 1; i <= max(n, m); ++i) pw[i] = pw[i-1] * 2;
    int f0 = 1, f1 = 1, cntx = n, cnty = m, fx = 0, fy = 0;
    vector<int> cnt(2);
    vector<vector<int>> cntr(n, vector<int>(2, 0)), cntc(m, vector<int>(2, 0));
    map<pair<int,int>, int> mp;
    auto Erase = [&](int x, int y) {
        if(!mp.count({x, y})) return;
        int p = mp[{x, y}];
        mp.erase({x, y});
        if(--cntr[x][p ^ y & 1] == 0) {
            if(cntr[x][p ^ y & 1 ^ 1]) fx--;
            else cntx += 1;
        }
        if(--cntc[y][p ^ x & 1] == 0) {
            if(cntc[y][p ^ x & 1 ^ 1]) fy--;
            else cnty += 1;
        }
        --cnt[x & 1 ^ y & 1 ^ p];
    };
    auto Insert = [&](int x, int y, int p) {
        mp[{x, y}] = p;
        if(cntr[x][p ^ y & 1]++ == 0) {
            if(cntr[x][p ^ y & 1 ^ 1]) fx++;
            else cntx -= 1;
        }
        if(cntc[y][p ^ x & 1]++ == 0) {
            if(cntc[y][p ^ x & 1 ^ 1]) fy++;
            else cnty -= 1;
        }
        ++cnt[x & 1 ^ y & 1 ^ p];
    };
    while(k--) {
        int x, y, op;
        cin >> x >> y >> op;
        --x, --y;
        Erase(x, y);
        if(op != -1) Insert(x, y, op);
        mint ans = -(cnt[0] == 0) - (cnt[1] == 0);
        if(fx == 0) ans += pw[cntx];
        if(fy == 0) ans += pw[cnty];
        cout << ans << '\n';
    }
}