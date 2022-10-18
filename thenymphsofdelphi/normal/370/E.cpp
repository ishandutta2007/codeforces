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

const int N = 2e5 + 5;

int n;
int a[N];

pii dp[N][6];
int arrans[N];

void trivial_impossible(){
    if (a[1] != 0 and a[1] != 1){
        cout << -1 << endl;
        exit(0);
    }
    int mx = 0;
    ForE(i, 1, n){
        if (!a[i]){
            continue;
        }
        if (a[i] < mx){
            cout << -1 << endl;
            exit(0);
        }
        mx = a[i];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    trivial_impossible();
    dp[1][1] = {1, 1};
    ForE(i, 2, n){
        if (a[i]){
            bool ck = 0;
            ForE(j, 2, 5){
                if (dp[i - 1][j].fi and dp[i - 1][j].fi <= a[i] - 1 and a[i] - 1 <= dp[i - 1][j].se){
                    ck = 1;
                    break;
                }
            }
            if (ck){
                dp[i][1] = {a[i], a[i]};
            }
            else{
                dp[i][1] = {0, 0};
            }
            ForE(j, 2, 5){
                if (dp[i - 1][j - 1].fi and dp[i - 1][j - 1].fi <= a[i] and a[i] <= dp[i - 1][j - 1].se){
                    dp[i][j] = {a[i], a[i]};
                }
                else{
                    dp[i][j] = {0, 0};
                }
            }
            continue;
        }
        ForE(j, 2, 5){
            if (dp[i - 1][j].fi){
                if (!dp[i][1].fi or dp[i][1].fi > dp[i - 1][j].fi + 1){
                    dp[i][1].fi = dp[i - 1][j].fi + 1;
                }
                if (!dp[i][1].se or dp[i][1].se < dp[i - 1][j].se + 1){
                    dp[i][1].se = dp[i - 1][j].se + 1;
                }
            }
        }
        ForE(j, 2, 5){
            dp[i][j] = dp[i - 1][j - 1];
        }
    }
    int ans = 0, y = 1, val;
    ForE(j, 2, 5){
        if (ans < dp[n][j].se){
            ans = dp[n][j].se;
            y = j;
            val = dp[n][j].se;
        }
    }
    if (!ans){
        cout << -1 << endl;
        return 0;
    }
    FordE(i, n, 2){
        arrans[i] = val;
        int ty, tval;
        if (y == 1){
            ForE(j, 2, 5){
                if (dp[i - 1][j].fi and dp[i - 1][j].fi <= val - 1 and val - 1 <= dp[i - 1][j].se){
                    ty = j;
                    break;
                }
            }
            tval = val - 1;
        }
        else{
            ty = y - 1;
            tval = val;
        }
        y = ty; val = tval;
    }
    arrans[1] = 1;
    cout << ans << endl;
    ForE(i, 1, n){
        cout << arrans[i] << ' ';
    } cout << endl;
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