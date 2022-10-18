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

const int maxN = 5e3 + 5, inf = 1e9 + 7;

int n, s, e;
int x[maxN], a[maxN], b[maxN], c[maxN], d[maxN];

ll dp[maxN][maxN];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> s >> e;
    ForE(i, 1, n){
        cin >> x[i];
    }
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, n){
        cin >> b[i];
    }
    ForE(i, 1, n){
        cin >> c[i];
    }
    ForE(i, 1, n){
        cin >> d[i];
    }

    x[n + 1] = inf;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    int cap = 0;
    ForE(i, 1, n){
        ForE(cc, 1, n){
            if (i == s){
                if (cap == 1 and i != n and cc == 1){
                    continue;
                }
                // new cc
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc - 1] + (ll)(2 * cc - 1 - cap) * (x[i + 1] - x[i]) + d[i]);
                // left of cc
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc] + (ll)(2 * cc - 1 - cap) * (x[i + 1] - x[i]) + c[i]);
                continue;
            }
            if (i == e){
                if (cap == 1 and i != n and cc == 1){
                    continue;
                }
                // new cc
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc - 1] + (ll)(2 * cc - 1 - cap) * (x[i + 1] - x[i]) + b[i]);
                // right of cc
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc] + (ll)(2 * cc - 1 - cap) * (x[i + 1] - x[i]) + a[i]);
                continue;
            }
            // new cc
            if (!(cap == 2 and cc == 1)){
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc - 1] + (ll)(2 * cc - cap) * (x[i + 1] - x[i]) + b[i] + d[i]);
            }
            // left of cc
            if (!(i > s and cc == 1)){
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc] + (ll)(2 * cc - cap) * (x[i + 1] - x[i]) + b[i] + c[i]);
            }
            // right of cc
            if (!(i > e and cc == 1)){
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc] + (ll)(2 * cc - cap) * (x[i + 1] - x[i]) + a[i] + d[i]);
            }
            // merge cc
            if (!(cap == 2 and i != n and cc == 1)){
                dp[i][cc] = min(dp[i][cc], dp[i - 1][cc + 1] + (ll)(2 * cc - cap) * (x[i + 1] - x[i]) + a[i] + c[i]);
            }
        }
        if (i == s or i == e){
            cap++;
        }
    }
    cout << dp[n][1] << endl;
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