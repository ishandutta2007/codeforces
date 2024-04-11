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

const int INF = 2e9;
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

int t_val[4*N], t_add[4*N];

void push(int v) {
    t_val[v] += t_add[v];
    t_add[2*v+2] += t_add[v];
    t_add[2*v+1] += t_add[v];
    t_add[v] = 0;
}

void add(int v, int vl, int vr, int l, int r, int dx) {
    if(l > vr  || vl > r)  return;
    if(vl != vr) push(v);
    if(l <= vl && vr <= r) t_add[v] += dx;
    else {
        int vm = (vl + vr) / 2;
        add(2*v+1, vl,   vm, l, r, dx);
        add(2*v+2, vm+1, vr, l, r, dx);
        t_val[v] = max(t_val[2*v+1]+t_add[2*v+1],
                       t_val[2*v+2]+t_add[2*v+2]);
    }
}

int get_max(int v, int vl, int vr, int l, int r) {
    if(l > vr  || vl > r) return 0;
    if(l <= vr && vr <= r) return t_add[v] + t_val[v];
    int vm = (vl + vr) / 2; push(v);
    return max(get_max(2*v+1, vl,   vm, l, r),
               get_max(2*v+2, vm+1, vr, l, r));
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, p; cin >> n >> m >> p;
    vpi a(n); for(pi& x : a) cin >> x.F >> x.S;
    vpi b(m); for(pi& x : b) cin >> x.F >> x.S;
    vector<pair<pi, int>> z(p);
    for(auto& x : z) cin >> x.F.F >> x.F.S >> x.S;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(z.begin(), z.end());
    int res = -INF;
    for(int i = 0; i < m; ++i) add(0, 0, m-1, i, i, -b[i].S);
    for(int i = 0, j = 0; i < n; ++i) {
        for(; j < p && z[j].F.F < a[i].F; ++j) {
            int ind = upper_bound(b.begin(), b.end(), pair<int,int>(z[j].F.S, INF)) - b.begin();
            if(ind != b.size()) add(0, 0, m-1, ind, m-1, z[j].S);
        }

        ckmax(res, get_max(0, 0, m-1, 0, m-1) - a[i].S);
    }
    cout << res << endl;
}