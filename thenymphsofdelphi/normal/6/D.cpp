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

const int N = 1e1 + 5, M = 15 + 5;

int n, a, b;
int h[N];

int dp[N][M][M];
pair <tuple <int, int, int>, int> trace[N][M][M];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> a >> b;
    ForE(i, 1, n){
        cin >> h[i]; h[i]++;
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[2][h[2 - 1]][h[2]] = 0;
    For(i, 2, n){
        int ti = i + 1;
        For(j, 0, M){
            For(k, 0, M){
                ForE(x, 0, 16){
                    int l = j - b * x, tj = k - a * x, tk = h[ti] - b * x;
                    l = max(l, 0); tj = max(tj, 0); tk = max(tk, 0);
                    if (l){
                        continue;
                    }
                    if (dp[ti][tj][tk] > dp[i][j][k] + x){
                        dp[ti][tj][tk] = dp[i][j][k] + x;
                        trace[ti][tj][tk] = make_pair(make_tuple(i, j, k), x);
                    }
                }
            }
        }
    }
    int i = n, j = 0, k = 0;
    cout << dp[i][j][k] << endl;
    while (i != 2){
        int ti, tj, tk;
        tie(ti, tj, tk) = trace[i][j][k].fi;
        ForE(x, 1, trace[i][j][k].se){
            cout << i - 1 << ' ';
        }
        tie(i, j, k) = make_tuple(ti, tj, tk);
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