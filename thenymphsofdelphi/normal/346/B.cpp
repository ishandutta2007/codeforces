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

const int N = 1e2 + 5;

string s, t, u;

int nxt[N][26];
int dp[N][N][N];
tuple <int, int, int> trace[N][N][N];

void smax(int i1, int j1, int k1, int i2, int j2, int k2, int val){
    if (dp[i1][j1][k1] < val){
        dp[i1][j1][k1] = val;
        trace[i1][j1][k1] = make_tuple(i2, j2, k2);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> s >> t >> u;

    For(i, 0, isz(u)){
        For(c, 0, 26){
            string tu = u.substr(0, i);
            tu += c + 'A';
            FordE(len, min(isz(u), isz(tu)), 0){
                bool ck = 1;
                For(j, 0, len){
                    if (u[j] != tu[isz(tu) - (len - j)]){
                        ck = 0;
                        break;
                    }
                }
                if (ck){
                    nxt[i][c] = len;
                    break;
                }
            }
        }
    }
    memset(dp, 0xc0, sizeof(dp));
    For(i, 0, N){
        dp[0][i][0] = dp[i][0][0] = 0;
    }
    ForE(i, 0, isz(s)){
        ForE(j, 0, isz(t)){
            For(k, 0, isz(u)){
                smax(i, j + 1, k, i, j, k, dp[i][j][k]);
                smax(i + 1, j, k, i, j, k, dp[i][j][k]);
                if (i != isz(s) and j != isz(t) and s[i] == t[j]){
                    smax(i + 1, j + 1, nxt[k][s[i] - 'A'], i, j, k, dp[i][j][k] + 1);
                }
            }
        }
    }
    int ans = 0; tuple <int, int, int> pos;
    For(k, 0, isz(u)){
        if (ans < dp[isz(s)][isz(t)][k]){
            ans = dp[isz(s)][isz(t)][k];
            pos = make_tuple(isz(s), isz(t), k);
        }
    }
    if (ans == 0){
        cout << 0 << endl;
        return 0;
    }
    string sans;
    while (1){
        int i, j, k; tie(i, j, k) = pos;
        if (i == 0 or j == 0){
            break;
        }
        int i2, j2, k2; tie(i2, j2, k2) = trace[i][j][k];
        if (i2 != i and j2 != j){
            sans += s[i - 1];
        }
        pos = trace[i][j][k];
    }
    reverse(bend(sans));
    cout << sans << endl;
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