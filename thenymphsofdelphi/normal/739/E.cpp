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

const int N = 2e3 + 5, inf = 1e9 + 7;
const double eps = 1e-7;

int n, m, k;
double a[N], b[N];

pair <double, int> dp[N][N];

void update_dp(pair <double, int> &dp, const pair <double, int> &tdp){
    if (abs(dp.fi - tdp.fi) <= eps){
        if (dp.se < tdp.se){
            dp = tdp;
        }
    }
    else if (dp.fi < tdp.fi){
        dp = tdp;
    }
}

pair <double, int> lagrange_multiplier(double lambda){
    ForE(x, 1, m){
        dp[0][x] = make_pair(-inf, 0);
    }
    dp[0][0] = make_pair(0, 0);
    ForE(i, 1, n){
        ForE(x, 0, min(i, m)){
            dp[i][x] = dp[i - 1][x];
            update_dp(dp[i][x], make_pair(dp[i - 1][x].fi + b[i] + lambda, dp[i - 1][x].se + 1));
            if (x){
                update_dp(dp[i][x], make_pair(dp[i - 1][x - 1].fi + a[i], dp[i - 1][x - 1].se));
                update_dp(dp[i][x], make_pair(dp[i - 1][x - 1].fi + (1 - (1 - a[i]) * (1 - b[i])) + lambda, dp[i - 1][x - 1].se + 1));
            }
        }
    }
    return dp[n][m];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    
    double lo = -1, hi = 1;
    ForE(turn, 1, 30){
        double mid = (lo + hi) / 2;
        
        pair <double, int> val = lagrange_multiplier(mid);
        if (val.se <= k){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    pair <double, int> val = lagrange_multiplier(lo);
    cout << fixed << setprecision(6) << val.fi - k * lo << endl;
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