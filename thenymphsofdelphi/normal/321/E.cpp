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

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 4e3 + 5, K = 8e2 + 5, inf = 1e9 + 7;

int n, k;
int a[N][N], b[N][N], c[N][N];
int dp[K][N];

void caldp(int i, int l, int r, int tl, int tr){
    if (l > r){
        return;
    }
    int mid = (l + r) >> 1;
    dp[i][mid] = inf;
    int tm = tl - 1;
    ForE(j, tl, tr){
        if (dp[i][mid] > dp[i - 1][j] + c[j + 1][mid]){
            dp[i][mid] = dp[i - 1][j] + c[j + 1][mid];
            tm = j;
        }
    }
    caldp(i, l, mid - 1, tl, tm);
    caldp(i, mid + 1, r, tm, tr);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        ForE(j, 1, n){
            char c; cin >> c; a[i][j] = c - '0';
            b[i][j] = b[i][j - 1] + a[i][j];
        }
    }
    ForE(i, 1, n){
        ForE(j, i, n){
            c[i][j] = c[i][j - 1] + b[j][j] - b[j][i - 1];
        }
        For(j, 1, i){
            c[i][j] = inf;
        }
    }
    ForE(j, 1, n){
        dp[0][j] = inf;
    }
    ForE(i, 1, k){
        caldp(i, 1, n, 0, n - 1);
    }
    cout << dp[k][n] << endl;
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