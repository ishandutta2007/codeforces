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

const int N = 2e5+7;

int d[N], q[N], p[N], k, n, m, a, b;
vi g[N], g_rev[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        g[a-1].pb(b-1), g_rev[b-1].pb(a-1);
    }
    cin >> k;
    for(int i = 0; i < k; --p[i++]) cin >> p[i];
    for(int i = 0; i < n; ++i) d[i] = INF;
    queue<int> qe; qe.push(p[k-1]); d[p[k-1]] = 0; q[p[k-1]] = 1;
    while(!qe.empty()) {
        int v = qe.front(); qe.pop();
        for(int to : g_rev[v]) {
            if(d[to] == INF) d[to] = d[v] + 1, q[to] = 1, qe.push(to);
            else if(d[to] == d[v] + 1) ++q[to];
        }
    }

    //cout << "d: ";for(int i = 0; i < n; ++i) cout << ' ' << d[i]; cout << endl;
    //cout << "q: ";for(int i = 0; i < n; ++i) cout << ' ' << q[i]; cout << endl;

    for(int i = 0; i < k - 1; ++i) {
        if(d[p[i+1]] > d[p[i]]-1) ++a, ++ b;
        else if(q[p[i]] > 1) ++ b;
        //cout << i+1 << ' ' << a << ' ' << b << endl;
    }

    cout << a << ' ' << b << endl;
}