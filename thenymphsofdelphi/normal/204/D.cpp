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

const int N = 1e6 + 5, mod = 1e9 + 7;

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
int a[N];

int can0[N], can1[N];

int dp0[N][3], dp1[N][3]; // 0: pref, 1: suff; 0, 1: val false, 2: true
int sumdp10[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        char c; cin >> c;
        if (c == 'B'){
            a[i] = 0;
        }
        else if (c == 'W'){
            a[i] = 1;
        }
        else{
            a[i] = 2;
        }
        can0[i] = can0[i - 1] + (a[i] == 0 or a[i] == 2 ? 1 : 0);
        can1[i] = can1[i - 1] + (a[i] == 1 or a[i] == 2 ? 1 : 0);
    }
    dp0[0][1] = 1;
    ForE(i, 1, n){
        if (i - k >= 0 and can0[i] - can0[i - k] == k){
            dp0[i][2] = dp0[i - k][1];
        }
        if (a[i] == 0){
            dp0[i][0] = add(dp0[i - 1][0], dp0[i - 1][1]);
        }
        else if (a[i] == 1){
            dp0[i][1] = add(dp0[i - 1][0], dp0[i - 1][1]);
        }
        else{
            dp0[i][0] = add(dp0[i - 1][0], dp0[i - 1][1]);
            dp0[i][1] = add(dp0[i - 1][0], dp0[i - 1][1]);
        }
        ssub(dp0[i][0], dp0[i][2]);
    }
    dp1[n + 1][0] = 1;
    sumdp10[n + 1] = 1;
    FordE(i, n, 1){
        if (i + k <= n + 1 and can1[i + k - 1] - can1[i - 1] == k){
            dp1[i][2] = dp1[i + k][0];
        }
        if (a[i] == 0){
            dp1[i][0] = add(dp1[i + 1][0], dp1[i + 1][1]);
        }
        else if (a[i] == 1){
            dp1[i][1] = add(dp1[i + 1][0], dp1[i + 1][1]);
        }
        else{
            dp1[i][0] = add(dp1[i + 1][0], dp1[i + 1][1]);
            dp1[i][1] = add(dp1[i + 1][0], dp1[i + 1][1]);
        }
        ssub(dp1[i][1], dp1[i][2]);
        sumdp10[i] = sumdp10[i + 1];
        if (a[i] == 2){
            sadd(sumdp10[i], sumdp10[i + 1]);
        }
    }
    int ans = 0;
    ForE(i, 1, n){
        sadd(ans, mul(dp0[i][2], sub(sumdp10[i + 1], add(dp1[i + 1][0], dp1[i + 1][1]))));
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