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

const int N = 2e3 + 5, M = 11, mod = 998244353;

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
int len[N], sum[N];

int dp[N][N][M];

void caldp(const vi& a){
    dp[0][0][0] = 1;
    ForE(i, 1, isz(a)){
        ForE(j, 0, i){
            For(k, 0, M){
                dp[i][j][k] = 0;
            }
            if (j != 0){
                int tk = M - 1 - sum[a[i - 1]];
                For(k, 0, M){
                    tk++; if (tk == M) tk = 0;
                    sadd(dp[i][j][k], dp[i - 1][j - 1][tk]);
                }
            }
            if (j != i){
                int tk = (M - 1 + sum[a[i - 1]]) % M;
                For(k, 0, M){
                    tk++; if (tk == M) tk = 0;
                    sadd(dp[i][j][k], dp[i - 1][j][tk]);
                }
            }
            For(k, 0, M){
                // cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
            }
        }
    }
}

int ans1[M], ans2[M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
calfac();
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        len[i] = 0; sum[i] = 0;
        while (a[i]){
            len[i]++; if (len[i] & 1) sum[i] += a[i] % 10; else sum[i] -= a[i] % 10;
            a[i] /= 10;
        }
        sum[i] = (sum[i] % M + M) % M;
        if (!(len[i] & 1)){
            sum[i] = (M - sum[i]) % M;
        }
    }
    vi lenodd, leneven;
    ForE(i, 1, n){
        if (len[i] & 1){
            lenodd.emplace_back(i);
        }
        else{
            leneven.emplace_back(i);
        }
    }
    caldp(lenodd);
    For(j, 0, M){
        ans1[j] = mul(dp[isz(lenodd)][(isz(lenodd) + 1) / 2][j], mul(fac[(isz(lenodd) + 1) / 2], fac[isz(lenodd) / 2]));
    }
    caldp(leneven);
    int num1 = isz(lenodd) / 2 + 1, num2 = (isz(lenodd) + 1) / 2;
    For(j, 0, M){
        ans2[j] = 0;
        if (isz(lenodd) == 0){
            if (dp[isz(leneven)][isz(leneven)][j] == 1){
                ans2[j] = fac[isz(leneven)];
            }
            else{
                ans2[j] = 0;
            }
        }
        else{
            ForE(i, 0, isz(leneven)){
                ans2[j] = add(ans2[j], mul(dp[isz(leneven)][i][j], mul(P(i + num1 - 1, i), P(isz(leneven) - i + num2 - 1, isz(leneven) - i))));
            }
        }
    }
    int ans = 0;
    For(j1, 0, M){
        int j2 = M - j1; if (j2 == M) j2 = 0;
        ans = add(ans, mul(ans1[j1], ans2[j2]));
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