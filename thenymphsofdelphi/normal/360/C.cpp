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

const int N = 2e3 + 5, K = 3e3 + 5, mod = 1e9 + 7;

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

int n, k;
string s;

int dp[N][K], prefdp[N][K];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    cin >> s; s = ' ' + s;

    dp[0][0] = 1;
    prefdp[0][0] = 1;
    ForE(i, 1, n){
        ForE(j, 0, k){
            dp[i][j] = mul(prefdp[i - 1][j], s[i] - 'a');
            ForE(x, 0, n){
                if (i - 1 - x < 0 or j - (x + 1) * (n - i + 1) < 0){
                    break;
                }
                sadd(dp[i][j], mul('z' - s[i], dp[i - 1 - x][j - (x + 1) * (n - i + 1)]));
            }
            prefdp[i][j] = add(prefdp[i - 1][j], dp[i][j]);
        }
    }
    cout << prefdp[n][k];
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