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

const int N = 5e2 + 5, inf = 1e9 + 7;

int n;
int a[N][N];

ll ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, 2 * n){
        ForE(j, 1, 2 * n){
            cin >> a[i][j];
        }
    }
    ans = 0;
    ForE(i, n + 1, 2 * n){
        ForE(j, n + 1, 2 * n){
            ans += a[i][j];
        }
    }
    int mn = inf;
    mn = min(mn, a[1][n + 1]);
    mn = min(mn, a[1][2 * n]);
    mn = min(mn, a[n][n + 1]);
    mn = min(mn, a[n][2 * n]);
    mn = min(mn, a[n + 1][1]);
    mn = min(mn, a[n + 1][n]);
    mn = min(mn, a[2 * n][1]);
    mn = min(mn, a[2 * n][n]);
    ans += mn;
    cout << ans << endl;
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