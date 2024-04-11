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
    mint operator -() {return mint(x == 0 ? 0 : mod - x);}
    friend mint operator +(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret += rhs;}
    friend mint operator -(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret -= rhs;}
    friend mint operator *(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret *= rhs;}
    friend mint operator /(const mint &lhs, const mint &rhs) {mint ret(lhs); return ret /= rhs;}
    friend ostream& operator <<(ostream &os, const mint &rhs) {os << rhs.x; return os;}
    friend istream& operator >>(istream &is, mint &rhs) {ll a; is >> a; rhs = a; return is;}
};
mint fpow(mint a,ll b){mint r=1;for(;b;b>>=1){if(b&1)r=r*a;a=a*a;}return r;}

const int maxn = 2e5 + 5;
struct node {
    int ls, rs;
    mint sum = 0, add = 0, mul = 1;
}a[maxn * 50]; int tot = 1;
void upd(mint v1, mint v2, int l, int r, int rt) {
    a[rt].sum = a[rt].sum * v1 + (r - l + 1) * v2;
    a[rt].mul *= v1;
    a[rt].add = a[rt].add * v1 + v2;
}
void pushdown(int l, int r, int rt) {
    if(!a[rt].ls) a[rt].ls = ++tot;
    if(!a[rt].rs) a[rt].rs = ++tot;
    int m = (l + r) / 2;
    upd(a[rt].mul, a[rt].add, l, m, a[rt].ls);
    upd(a[rt].mul, a[rt].add, m+1, r, a[rt].rs);
    a[rt].mul = 1, a[rt].add = 0;
}
void update(mint v1, mint v2, int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        upd(v1, v2, l, r, rt);
        return;
    }
    pushdown(l, r, rt);
    int m = (l + r) / 2;
    if(L <= m) update(v1, v2, L, R, l, m, a[rt].ls);
    if(m < R) update(v1, v2, L, R, m + 1, r, a[rt].rs);
    a[rt].sum = a[a[rt].ls].sum + a[a[rt].rs].sum;
}
const int N = 1e9;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<mint> dp(n + 1); dp[0] = 1;
    int rt = 1;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        update(0, 0, x + 1, N, 1, N, rt);
        update(-1, dp[i-1], 1, x, 1, N, rt);
        dp[i] = a[rt].sum;
    }
    cout << dp[n] << '\n';
}