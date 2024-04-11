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

const int N = 3e5 + 5, S = sqrt(N) + 5, mod = 1e9 + 9;

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

int n, q;
int a[N];

int fib[N], sumfib[N];
int idxbl[N]; pii lazy[N]; int sum[N];

void update(int id){
    int val1 = lazy[id].fi, val2 = lazy[id].se;
    sadd(a[(id - 1) * S + 1], val1);
    sadd(a[(id - 1) * S + 2], val2);
    ForE(i, (id - 1) * S + 3, id * S){
        sadd(val2, val1); val1 = sub(val2, val1);
        sadd(a[i], val2);
    }
    lazy[id].fi = 0; lazy[id].se = 0;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    ForE(i, 1, n){
        cin >> a[i];
    }

    fib[1] = 1; fib[2] = 1;
    ForE(i, 3, n){
        fib[i] = add(fib[i - 1], fib[i - 2]);
    }
    ForE(i, 1, n){
        sumfib[i] = add(sumfib[i - 1], fib[i]);
    }
    ForE(i, 1, n){
        idxbl[i] = (i + S - 1) / S;
    }
    ForE(i, 1, n){
        sadd(sum[idxbl[i]], a[i]);
    }
    while (q--){
        int type, l, r; cin >> type >> l >> r;
        int il = idxbl[l], ir = idxbl[r];
        if (type == 1){
            if (il == ir){
                ForE(i, l, r){
                    sadd(a[i], fib[i - l + 1]);
                    sadd(sum[il], fib[i - l + 1]);
                }
                continue;
            }
            int tl = l, tr = r;
            while (idxbl[tl] == il){
                sadd(a[tl], fib[tl - l + 1]);
                sadd(sum[il], fib[tl - l + 1]);
                tl++;
            }
            while (idxbl[tr] == ir){
                sadd(a[tr], fib[tr - l + 1]);
                sadd(sum[ir], fib[tr - l + 1]);
                tr--;
            }
            ForE(i, il + 1, ir - 1){
                sadd(lazy[i].fi, fib[tl - l + 1]);
                sadd(lazy[i].se, fib[tl + 1 - l + 1]);
                sadd(sum[i], sub(sumfib[tl + S - 1 - l + 1], sumfib[tl - 1 - l + 1]));
                tl += S;
            }
        }
        else{
            update(il);
            update(ir);
            int ans = 0;
            if (il == ir){
                ForE(i, l, r){
                    sadd(ans, a[i]);
                }
                cout << ans << endl;
                continue;
            }
            int tl = l, tr = r;
            while (idxbl[tl] == il){
                sadd(ans, a[tl]);
                tl++;
            }
            while (idxbl[tr] == ir){
                sadd(ans, a[tr]);
                tr--;
            }
            ForE(i, il + 1, ir - 1){
                sadd(ans, sum[i]);
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