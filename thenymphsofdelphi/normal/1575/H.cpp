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

const int N = 5e2 + 5;

__attribute__((always_inline)) void smin(int& x, int y){
    if (x > y){
        x = y;
    }
}

int n, m;
string s, t;

int nxt[N][2];
int dp[N][N][N]; // pref s i, cnt j, pref t k

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> m;
    cin >> s >> t;
    s = ' ' + s; t = ' ' + t;

    ForE(i, 0, m){
        For(j, 0, 2){
            FordE(k, min(m, i + 1), 1){
                bool ck = 1;
                ForE(l, 1, k){
                    if ((l == k ? (char)(j + '0') : t[i + 1 - k + l]) != t[l]){
                        ck = 0;
                        break;
                    }
                }
                if (ck){
                    nxt[i][j] = k;
                    break;
                }
            }
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    For(i, 0, n){
        ForE(j, 0, n - m + 1){
            ForE(k, 0, m){
                smin(dp[i + 1][j + (nxt[k][0] == m ? 1 : 0)][nxt[k][0]], dp[i][j][k] + (0 == s[i + 1] - '0' ? 0 : 1));
                smin(dp[i + 1][j + (nxt[k][1] == m ? 1 : 0)][nxt[k][1]], dp[i][j][k] + (1 == s[i + 1] - '0' ? 0 : 1));
            }
        }
    }
    ForE(j, 0, n - m + 1){
        int ans = N;
        ForE(k, 0, m){
            smin(ans, dp[n][j][k]);
        }
        cout << (ans == N ? -1 : ans) << ' ';
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