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

const int N = 1e5 + 5, mod = 998244353;

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

int n;
int a[N];

int szval[2]; pii val[2][N]; // cell, cnt
int szdp[2]; pii dp[2][N]; // dp, cnt
int ans;

void calval(int i){
    int ii = i & 1;
    szval[ii] = 0;
    int s = sqrt(a[i]);
    int x = 1;
    while (1){
        int y = (a[i] + x - 1) / x;
        if (y > s){
            val[ii][szval[ii]++] = make_pair(y, x);
            x++;
        }
        else{
            break;
        }
    }
    FordE(y, s, 1){
        val[ii][szval[ii]++] = make_pair(y, (a[i] + y - 1) / y);
    }
    szdp[ii] = szval[ii];
    For(j, 0, szdp[ii]){
        dp[ii][j] = make_pair(0, 0);
    }
}

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

    ans = 0;
    calval(n);
    dp[n & 1][0].se = 1;
    FordE(i, n - 1, 1){
        calval(i);
        int ii = i & 1;
        int j1 = 0, j2 = 0;
        pii tans = make_pair(0, 0);
        while (j1 < szval[ii] or j2 < szval[ii ^ 1]){
            if (j2 == szval[ii ^ 1]){
                dp[ii][j1] = tans;
                j1++;
                tans = make_pair(0, 0);
                continue;
            }
            if (val[ii][j1].fi <= a[i + 1] / val[ii ^ 1][j2].se){
                sadd(tans.fi, dp[ii ^ 1][j2].fi);
                sadd(tans.se, dp[ii ^ 1][j2].se);
                j2++;
            }
            else{
                dp[ii][j1] = tans;
                j1++;
                tans = make_pair(0, 0);
            }
        }
        sadd(dp[ii][0].se, 1);
        For(j1, 0, szval[ii]){
            sadd(dp[ii][j1].fi, mul(val[ii][j1].se - 1, dp[ii][j1].se));
            sadd(ans, dp[ii][j1].fi);
        }
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