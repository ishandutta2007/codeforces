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


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; char c;
        cin >> n >> c;
        string s;
        cin >> s;
        if(count(s.begin(), s.end(), c) == s.size()) {
            cout << 0 << '\n';
        } else {
            int ans = -1;
            for(int i = 1; i <= n; ++i) {
                int ok = 1;
                for(int j = i; j <= n; j += i) {
                    if(s[j - 1] != c) ok = 0;
                }
                if(ok == 1) {
                    ans = i;
                    break;
                }
            }
            if(ans != -1) {
                cout << 1 << "\n" << ans << "\n";
            } else {
                cout << 2 << "\n";
                cout << n - 1 << " " << n << "\n";
            }
        }
    }
}