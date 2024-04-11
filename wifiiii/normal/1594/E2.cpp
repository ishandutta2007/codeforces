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

const int maxn = 200006;
int tr[maxn][2], mark[maxn], tot = 0;

int main() {
    int n;
    cin >> n;
    int m;
    cin >> m;
    memset(mark, -1, sizeof(mark));
    while(m--) {
        ll x;
        string s;
        cin >> x >> s;
        int c = 0;
        if(s == "orange") c = 0;
        if(s == "red") c = 1;
        if(s == "blue") c = 2;
        if(s == "green") c = 3;
        if(s == "white") c = 4;
        if(s == "yellow") c = 5;

        vector<int> path;
        while(x) {
            if(x & 1) path.push_back(1);
            else path.push_back(0);
            x >>= 1;
        }
        path.pop_back();
        reverse(path.begin(), path.end());
        int p = 0;
        for(int i : path) {
            if(!tr[p][i]) tr[p][i] = ++tot;
            p = tr[p][i];
        }
        mark[p] = c;
    }
    vector<vector<mint>> dp(tot + 1, vector<mint>(7));
    vector<vector<int>> vis(tot + 1, vector<int>(7));
    function<mint(int,int,int)> dfs = [&](int p, int dep, int last) -> mint {
        if(vis[p][last]) return dp[p][last];
        vis[p][last] = 1;
        if(mark[p] != -1) {
            if(last == mark[p] || (last ^ 1) == mark[p]) return dp[p][last] = 0;
            mint ret = 1;
            if(tr[p][0]) ret *= dfs(tr[p][0], dep - 1, mark[p]);
            else ret *= fpow(4, (1ll << dep) - 1);
            if(tr[p][1]) ret *= dfs(tr[p][1], dep - 1, mark[p]);
            else ret *= fpow(4, (1ll << dep) - 1);
            return dp[p][last] = ret;
        } else {
            mint ret = 0;
            for(int i = 0; i < 6; ++i) {
                if(last == i || (last ^ 1) == i) continue;
                mint tmp = 1;
                if(tr[p][0]) tmp *= dfs(tr[p][0], dep - 1, i);
                else tmp *= fpow(4, (1ll << dep) - 1);
                if(tr[p][1]) tmp *= dfs(tr[p][1], dep - 1, i);
                else tmp *= fpow(4, (1ll << dep) - 1);
                ret += tmp;
            }
            return dp[p][last] = ret;
        }
    };
    cout << dfs(0, n - 1, 6) << '\n';
}