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

const int N = 5e3 + 5;
const ll infll = (ll)1e18 + 7;

int n, X, Y;
string s, t;

ll dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> X >> Y;
    cin >> s; s = ' ' + s;
    cin >> t; t = ' ' + t;

    int sum = 0;
    ForE(i, 1, n){
        s[i] = (s[i] == t[i] ? '0' : '1');
        sum += (s[i] == '1');
    }
    if (sum % 2 == 1){
        cout << -1 << endl;
        continue;
    }
    if (sum == 0){
        cout << 0 << endl;
        continue;
    }

    if (X >= Y){
        int mnpos = 0, mxpos = 0;
        ForE(i, 1, n){
            if (s[i] == '1'){
                if (mnpos == 0){
                    mnpos = i;
                }
                mxpos = i;
            }
        }
        if (sum == 2 and mnpos + 1 == mxpos){
            cout << min(X, 2 * Y) << endl;
            continue;
        }
        cout << (ll)sum / 2 * Y << endl;
        continue;
    }
    vi a;
    ForE(i, 1, n){
        if (s[i] == '1'){
            a.emplace_back(i);
        }
    }
    ForE(j, 1, n){
        dp[0][j] = infll;
    }
    dp[0][0] = 0;
    For(i, 0, isz(a)){
        ForE(j, 0, n){
            dp[i + 1][j] = dp[i][j];
            if (i != 0 and j != 0){
                dp[i + 1][j] = min(dp[i + 1][j], dp[i - 1][j - 1] + (ll)X * (a[i] - a[i - 1]));
            }
        }
    }

    ll ans = infll;
    ForE(j, 0, isz(a) / 2){
        ans = min(ans, dp[isz(a)][j] + (ll)Y * (isz(a) / 2 - j));
    }
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