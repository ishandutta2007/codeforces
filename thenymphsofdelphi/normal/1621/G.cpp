#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5, mod = 1e9 + 7;

inline void sadd(int& x, int y){
    if ((x += y) >= mod) x -= mod;
    return;
}

inline int add(int x, int y){
    if ((x += y) >= mod) x -= mod;
    return x;
}

inline void ssub(int& x, int y){
    if ((x -= y) < 0) x += mod;
    return;
}

inline int sub(int x, int y){
    if ((x -= y) < 0) x += mod;
    return x;
}

inline int mul(int x, int y){
    return 1ll * x * y % mod;
}

inline int binpow(int x, int y){
    int ans = 1;
    while (y){
        if (y & 1) ans = mul(ans, x);
        x = mul(x, x);
        y >>= 1;
    }
    return ans;
}

inline int inv(int x){
    return binpow(x, mod - 2);
}

#define div __div__
inline int div(int x, int y){
    return mul(x, binpow(y, mod - 2));
}

int fac[N], invfac[N];

void calfac(){
    fac[0] = invfac[0] = 1;
    For(i, 1, N){
        fac[i] = mul(fac[i - 1], i);
    }
    invfac[N - 1] = binpow(fac[N - 1], mod - 2);
    FordE(i, N - 2, 1){
        invfac[i] = mul(invfac[i + 1], i + 1);
    }
}

inline int C(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], mul(invfac[k], invfac[n - k]));
}

inline int P(int n, int k){
    if (n < 0 or k < 0 or k > n){
        return 0;
    }
    return mul(fac[n], invfac[n - k]);
}

template <typename T>
struct Segment_Tree_Max{
    static const T unit = 0;

    inline T f(T x, T y){
        return max(x, y);
    }

    int n;
    vector <T> seg;

    Segment_Tree_Max(int n = 1): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n);
    }

    void Build(int id, int l, int r){
        if (l == r){
            seg[id] = unit;
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid);
        Build(id << 1 | 1, mid + 1, r);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    Segment_Tree_Max(int n, vector <T>& a): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n, a);
    }

    void Build(int id, int l, int r, vector <T>& a){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid, a);
        Build(id << 1 | 1, mid + 1, r, a);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void Update(int i, T val){
        Update(1, 1, n, i, val);
    }

    void Update(int id, int l, int r, int i, T val){
        if (i < l || r < i){
            return;
        }
        if (i <= l && r <= i){
            seg[id] = f(seg[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        Update(id << 1, l, mid, i, val);
        Update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    T Get(int u, int v){
        if (u > v){
            return unit;
        }
        return Get(1, 1, n, u, v);
    }

    T Get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return unit;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return f(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
    }
};

template <typename T>
struct Segment_Tree_Sum{
    static const T unit = 0;

    inline T f(T x, T y){
        return add(x, y);
    }

    int n;
    vector <T> seg;

    Segment_Tree_Sum(int n = 1): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n);
    }

    void Build(int id, int l, int r){
        if (l == r){
            seg[id] = unit;
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid);
        Build(id << 1 | 1, mid + 1, r);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    Segment_Tree_Sum(int n, vector <T>& a): n(n) {
        seg.resize(4 * n + 1);
        Build(1, 1, n, a);
    }

    void Build(int id, int l, int r, vector <T>& a){
        if (l == r){
            seg[id] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        Build(id << 1, l, mid, a);
        Build(id << 1 | 1, mid + 1, r, a);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    void Update(int i, T val){
        Update(1, 1, n, i, val);
    }

    void Update(int id, int l, int r, int i, T val){
        if (i < l || r < i){
            return;
        }
        if (i <= l && r <= i){
            seg[id] = f(seg[id], val);
            return;
        }
        int mid = (l + r) >> 1;
        Update(id << 1, l, mid, i, val);
        Update(id << 1 | 1, mid + 1, r, i, val);
        seg[id] = f(seg[id << 1], seg[id << 1 | 1]);
    }

    T Get(int u, int v){
        if (u > v){
            return unit;
        }
        return Get(1, 1, n, u, v);
    }

    T Get(int id, int l, int r, int u, int v){
        if (v < l || r < u){
            return unit;
        }
        if (u <= l && r <= v){
            return seg[id];
        }
        int mid = (l + r) >> 1;
        return f(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
    }
};

Segment_Tree_Max <int> itmax;
Segment_Tree_Sum <int> itdp;

int n;
int a[N];

int m, b[N];
int r[N];

int dpl[N], dpr[N], dpivl[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    {
        vi vb(a + 1, a + n + 1);
        sort(bend(vb)); vb.erase(unique(bend(vb)), vb.end());
        m = isz(vb);
        ForE(i, 1, n){
            b[i] = lower_bound(bend(vb), a[i]) - vb.begin() + 1;
        }
    }
    itmax = Segment_Tree_Max <int>(m);
    FordE(i, n, 1){
        r[i] = itmax.Get(b[i] + 1, m) - 1;
        itmax.Update(b[i], i);
    }
    itdp = Segment_Tree_Sum <int>(m);
    ForE(i, 1, n){
        dpl[i] = add(itdp.Get(1, b[i] - 1), 1);
        itdp.Update(b[i], dpl[i]);
    }
    itdp.Build(1, 1, m);
    FordE(i, n, 1){
        dpr[i] = add(itdp.Get(b[i] + 1, m), 1);
        itdp.Update(b[i], dpr[i]);
    }
    itdp.Build(1, 1, m);
    int ans = 0;
    FordE(i, n, 1){
        if (r[i] == -1){
            continue;
        }
        sadd(ans, mul(dpl[i], dpr[i]));
        dpivl[i] = add(itdp.Get(b[i] + 1, b[r[i] + 1] - 1), 1);
        ssub(ans, mul(dpl[i], dpivl[i]));
        itdp.Update(b[i], dpivl[i]);
    }
    cout << ans << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/