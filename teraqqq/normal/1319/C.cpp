#include <bits/stdc++.h>

#define F first
#define S second
#define rsz resize
#define pb push_back

using namespace std;
using ll = long long;
using ld = double;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;

template<class T> bool ckmin(T& a, T b) { return b < a ? (a = b, true) : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? (a = b, true) : false; }

const int INF = 1e9;
const ll LINF = 1e18;
const ld PI = atan((ld)1)*4;

mt19937 rng(chrono::steady_clock().now().time_since_epoch().count());

const int MOD = 1e9+7;
struct Modular {
    int x;

    Modular(int x = 0) : x(x) { }
    Modular operator + (Modular b) { return Modular((x+b.x)%MOD); }
    Modular operator - (Modular b) { return Modular((x-b.x+MOD)%MOD); }
    Modular operator * (Modular b) { return Modular(((ll)x*b.x)%MOD); }

    Modular& operator += (Modular b) { x = (x+b.x)%MOD;     return *this; }
    Modular& operator -= (Modular b) { x = (x-b.x+MOD)%MOD; return *this; }
    Modular& operator *= (Modular b) { x = ((ll)x*b.x)%MOD; return *this; }

    bool operator == (Modular b) { return x==b.x; }
    bool operator != (Modular b) { return x!=b.x; }
    bool operator >= (Modular b) { return x>=b.x; }
    bool operator <= (Modular b) { return x<=b.x; }
    bool operator > (Modular b) { return x > b.x; }
    bool operator < (Modular b) { return x < b.x; }
};

template<class T> T fast_pow(T x, int n) {
    T res = 1;
    for(; n != 0; n >>= 1, x *= x) if(n&1) res *= x;
    return res;
}

int rev(int a, int m = MOD) {
    return a == 1 ? 1 : m - (ll) m * rev(m%a, a) / a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k = 0; cin >> n; string s; cin >> s;
    vi p(n), l(n), r(n);
    iota(p.begin(), p.end(), 0);
    iota(l.begin(), l.end(), -1);
    iota(r.begin(), r.end(), 1); r[n-1] = -1;
    sort(p.begin(), p.end(), [&s](int l, int r){ return s[l] != s[r] ? s[l] > s[r] : l < r; });
    for(int i : p) {
        //cout << i+1 << ": " << l[i]+1 << ' ' << r[i]+1 << endl;
        for(;;) {
            if(l[i] >= 0 && s[l[i]]+1 == s[i] || r[i] >= 0 && s[r[i]]+1 == s[i]) {
                ++k;
                if(l[i] >= 0) r[l[i]] = r[i];
                if(r[i] >= 0) l[r[i]] = l[i];
            }
            if(l[i] >= 0 && r[i] >= 0 && s[l[i]] == s[i] && s[i] == s[r[i]]+1) i = l[i];
            else break;
        }
    }
    cout << k << endl;
}