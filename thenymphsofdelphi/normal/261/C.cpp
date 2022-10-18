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

const int N = 40 + 5;

ll n, t;

ll dp[N][N][N];

vi vdig;

ll caldp(int pos, bool top, int k, int rk){
    if (pos == isz(vdig)){
        if (k == rk){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (dp[pos][top][k] != -1){
        return dp[pos][top][k];
    }
    dp[pos][top][k] = 0;
    int mxd = (top ? vdig[pos] : 1);
    ForE(d, 0, mxd){
        bool ttop = (top & (d == mxd));
        dp[pos][top][k] += caldp(pos + 1, ttop, k + d, rk);
    }
    // cout << "dp " << pos << ' ' << top << ' ' << k << endl;
    // cout << dp[pos][top][k] << endl;
    return dp[pos][top][k];
}

ll real_caldp(ll n, int k){
    memset(dp, -1, sizeof(dp));
    vdig.clear();
    while (n){
        vdig.emplace_back(n & 1);
        n >>= 1;
    }
    reverse(bend(vdig));
    return caldp(0, 1, 0, k);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> t;
    if (__builtin_popcount(t) != 1){
        cout << 0 << endl;
        return 0;
    }
    int k = __lg(t) + 1;
    cout << real_caldp(n + 1, k) - real_caldp(1, k) << endl;
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