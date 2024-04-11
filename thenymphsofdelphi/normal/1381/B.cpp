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

mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());
int randt(int l, int r){ return rando() % (r - l + 1) + l; }

const int N = 4e3 + 5;

int n;
int a[N], b[N];
vi c;
bool dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int q; cin >> q; while (q--){
    cin >> n;
    ForE(i, 1, 2 * n){
        cin >> a[i];
        b[a[i]] = i;
    }
    c.clear();
    int p = 2 * n + 1;
    FordE(i, 2 * n, 1){
        if (b[i] < p){
            c.emplace_back(p - b[i]);
            p = b[i];
        }
    }
    ForE(i, 0, isz(c)){
        ForE(j, 0, n){
            dp[i][j] = 0;
        }
    }
    dp[0][0] = 1;
    ForE(i, 1, isz(c)){
        ForE(j, 0, n){
            dp[i][j] = dp[i - 1][j];
            if (j >= c[i - 1]){
                dp[i][j] |= dp[i - 1][j - c[i - 1]];
            }
        }
    }
    if (dp[isz(c)][n]){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |

------------------------------    |
==================================+
*/