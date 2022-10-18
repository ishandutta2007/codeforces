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

const int N = 1e4 + 5, K = 1e4 + 5, LN = 50, mod = 1e9 + 7;

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

ll n; int k;

vector <pair <ll, int>> vfactor;
int dp[K][LN], prefdp[K][LN];
int ans = 1;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    {
        for (int i = 2; (ll)i * i <= n; i++){
            if (n % i){
                continue;
            }
            int cnt = 0;
            while (n % i == 0){
                cnt++; n /= i;
            }
            vfactor.emplace_back(i, cnt);
        }
        if (n != 1){
            vfactor.emplace_back(n, 1);
        }
    }
    Fora(&elem, vfactor){
        ll p; int cnt; tie(p, cnt) = elem;
        p %= mod;
        dp[0][0] = 1; prefdp[0][0] = 1;
        ForE(j, 1, cnt){
            dp[0][j] = mul(dp[0][j - 1], p);
            prefdp[0][j] = add(prefdp[0][j - 1], dp[0][j]);
        }
        ForE(i, 1, k){
            dp[i][0] = 1; prefdp[i][0] = 1;
            ForE(j, 1, cnt){
                dp[i][j] = div(prefdp[i - 1][j], j + 1);
                prefdp[i][j] = add(prefdp[i][j - 1], dp[i][j]);
            }
        }
        ans = mul(ans, dp[k][cnt]);
    }
    cout << ans << endl;
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