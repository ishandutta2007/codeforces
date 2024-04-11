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

const int N = 50 + 5, M = 1e5 + 5, mod = 998244353;

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

int n, m;
int l[N], r[N];
int ans[M];

int dp[2][M], prefdp[2][M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    ForE(i, 1, n){
        cin >> l[i] >> r[i];
    }
    FordE(k, m, 1){
        bool ck = 1;
        int tm = m / k;
        dp[0][0] = 1;
        prefdp[0][0] = 1;
        For(j, 1, tm){
            dp[0][j] = 0;
            prefdp[0][j] = 1;
        }
        ForE(i, 1, n){
            int tl = (l[i] + k - 1) / k, tr = r[i] / k;
            if (tl > tr){
                ck = 0;
                break;
            }
            ForE(j, 0, tm){
                if (j >= tl){
                    dp[i & 1][j] = sub(prefdp[(i & 1) ^ 1][j - tl], j - tr - 1 >= 0 ? prefdp[(i & 1) ^ 1][j - tr - 1] : 0);
                }
                else{
                    dp[i & 1][j] = 0;
                }
                prefdp[i & 1][j] = add(j ? prefdp[i & 1][j - 1] : 0, dp[i & 1][j]);
            }
        }
        if (!ck){
            ans[k] = 0;
            continue;
        }
        ans[k] = prefdp[n & 1][tm];
        for (int tk = 2 * k; tk <= m; tk += k){
            ssub(ans[k], ans[tk]);
        }
    }
    cout << ans[1] << endl;
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