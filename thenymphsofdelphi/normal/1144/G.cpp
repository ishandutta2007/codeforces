#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")

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

const int N = 2e5 + 5;

int n;
int a[N];
int dp[N][2];
int ans[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n) cin >> a[i];
    dp[1][0] = N; dp[1][1] = -1;
    ForE(i, 2, n){
        dp[i][0] = -1;
        if (a[i - 1] < a[i]){
            dp[i][0] = max(dp[i][0], dp[i - 1][0]);
        }
        if (dp[i - 1][1] < a[i]){
            dp[i][0] = max(dp[i][0], a[i - 1]);
        }
        dp[i][1] = N;
        if (a[i - 1] > a[i]){
            dp[i][1] = min(dp[i][1], dp[i - 1][1]);
        }
        if (dp[i - 1][0] > a[i]){
            dp[i][1] = min(dp[i][1], a[i - 1]);
        }
    }
    if (dp[n][0] == -1 and dp[n][1] == N){
        cout << "NO" << endl;
        return 0;
    }
    int j = -1;
    if (dp[n][0] != -1){
        j = 0;
    }
    else{
        j = 1;
    }
    ans[n] = j;
    FordE(i, n, 2){
        if (!j){
            if (dp[i - 1][1] < a[i] and dp[i][0] == a[i - 1]){
                j = 1;
            }
        }
        else{
            if (dp[i - 1][0] > a[i] and dp[i][1] == a[i - 1]){
                j = 0;
            }
        }
        ans[i - 1] = j;
    }
    cout << "YES" << endl;
    ForE(i, 1, n){
        cout << ans[i] << ' ';
    } cout << endl;
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