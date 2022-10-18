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

const int N = 5e3 + 5;
const ll infll = (ld)1e18 + 7;

int n;
int tag[N], s[N];

ll dp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n;
    ForE(i, 1, n){
        cin >> tag[i];
    }
    ForE(i, 1, n){
        cin >> s[i];
    }
    ForE(i, 1, n){
        dp[i] = 0;
    }
    ForE(r, 2, n){
        FordE(l, r - 1, 1){
            if (tag[l] != tag[r]){
                ll tdpl = dp[l], tdpr = dp[r];
                dp[l] = max(dp[l], tdpr + abs(s[l] - s[r]));
                dp[r] = max(dp[r], tdpl + abs(s[l] - s[r]));
            }
        }
    }
    ll ans = 0;
    ForE(i, 1, n){
        ans = max(ans, dp[i]);
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