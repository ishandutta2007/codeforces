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

const int N = 1e5 + 5;

int n, b, t;
int a[N];

int dp[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests >> n >> b >> t;
while (tests--){
    ForE(i, 1, n){
        cin >> a[i];
    }

    memset(dp, 0, sizeof(dp));
    t = min(t, b);
    ForE(iter, 1, t){
        ForE(i, 1, n){
            int val = dp[a[i] - 1] + 1;
            dp[a[i]] = max(dp[a[i]], val);
            int j = a[i] + 1;
            while (j <= b and dp[j] < dp[a[i]]){ // dp[j] <= t, so sum(dp[j]) <= t * n as well
                dp[j] = dp[a[i]];
                j++;
            }
        }
    }
    cout << dp[b] << endl;
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