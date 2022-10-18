#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 4e5 + 5, M = 3e2 + 1, mod = 1e9 + 7;

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

struct lazy_segment_tree_or{
    ll seg[4 * N], lazy[4 * N];

    void down(int id){
        if (lazy[id] == 0){
            return;
        }
        seg[id * 2] |= lazy[id];
        seg[id * 2 + 1] |= lazy[id];
        lazy[id * 2] |= lazy[id];
        lazy[id * 2 + 1] |= lazy[id];
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll val){
        if (v < l or r < u){
            return;
        }
        if (u <= l and r <= v){
            seg[id] |= val;
            lazy[id] |= val;
            return;
        }
        down(id);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        seg[id] = seg[id * 2] | seg[id * 2 + 1];
    }

    ll get(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return 0;
        }
        if (u <= l and r <= v){
            return seg[id];
        }
        down(id);
        int mid = (l + r) >> 1;
        return get(id * 2, l, mid, u, v) | get(id * 2 + 1, mid + 1, r, u, v);
    }
} itor;

struct lazy_segment_tree_mul{
    int seg[4 * N], lazy[4 * N];

    lazy_segment_tree_mul(){
        fill(seg, seg + 4 * N, 1);
        fill(lazy, lazy + 4 * N, 1);
    }

    void down(int id, int l, int r){
        if (lazy[id] == 1){
            return;
        }
        int mid = (l + r) >> 1;
        seg[id * 2] = mul(seg[id * 2], binpow(lazy[id], mid - l + 1));
        seg[id * 2 + 1] = mul(seg[id * 2 + 1], binpow(lazy[id], r - mid));
        lazy[id * 2] = mul(lazy[id * 2], lazy[id]);
        lazy[id * 2 + 1] = mul(lazy[id * 2 + 1], lazy[id]);
        lazy[id] = 1;
    }

    void update(int id, int l, int r, int u, int v, int val){
        if (v < l or r < u){
            return;
        }
        if (u <= l and r <= v){
            seg[id] = mul(seg[id], binpow(val, r - l + 1));
            lazy[id] = mul(lazy[id], val);
            return;
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, u, v, val);
        update(id * 2 + 1, mid + 1, r, u, v, val);
        seg[id] = mul(seg[id * 2], seg[id * 2 + 1]);
    }

    int get(int id, int l, int r, int u, int v){
        if (v < l or r < u){
            return 1;
        }
        if (u <= l and r <= v){
            return seg[id];
        }
        down(id, l, r);
        int mid = (l + r) >> 1;
        return mul(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
} itmul;

int lpf[M];
vi vprime;
int idxprime[M], revidxprime[M];

void sieve(){
    For(i, 2, M){
        if (lpf[i] == 0){
            lpf[i] = i;
            vprime.emplace_back(i);
            idxprime[i] = isz(vprime) - 1;
            revidxprime[idxprime[i]] = i;
        }
        for (int j = 0; j < isz(vprime) and vprime[j] <= lpf[i] and vprime[j] * i < M; j++){
            lpf[vprime[j] * i] = vprime[j];
        }
    }
}

int n, q;
int a[N];

int valinv[M];
ll msk[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }

    sieve();
    For(i, 1, M){
        valinv[i] = div(i - 1, i);
    }
    For(i, 1, M){
        int x = i;
        while (x != 1){
            msk[i] |= (1ll << idxprime[lpf[x]]);
            x /= lpf[x];
        }
    }
    ForE(i, 1, n){
        itor.update(1, 1, n, i, i, msk[a[i]]);
        itmul.update(1, 1, n, i, i, a[i]);
    }
    while (q--){
        string que; cin >> que;
        if (que == "MULTIPLY"){
            int l, r, x; cin >> l >> r >> x;
            itor.update(1, 1, n, l, r, msk[x]);
            itmul.update(1, 1, n, l, r, x);
        }
        else{
            int l, r; cin >> l >> r;
            ll mskrange = itor.get(1, 1, n, l, r); int ans = itmul.get(1, 1, n, l, r);
            FordE(bit, 63, 0){
                if (mskrange & (1ll << bit)){
                    ans = mul(ans, valinv[revidxprime[bit]]);
                }
            }
            cout << ans << endl;
        }
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