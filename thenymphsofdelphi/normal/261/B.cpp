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

const int N = 50 + 5;

int n;
int a[N];
int k;

double dp[N][N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }
    cin >> k;

    dp[0][0][0] = 1;
    ForE(i, 1, n){
        ForE(j, 0, i){
            double r = (double)j / i;
            ForE(tk, 0, k){
                dp[i][j][tk] = dp[i - 1][j][tk] * (1 - r);
                if (a[i] <= tk){
                    dp[i][j][tk] += dp[i - 1][j - 1][tk - a[i]] * r;
                }
            }
        }
    }

    double ans = 0;
    ForE(j, 1, n){
        ForE(tk, 0, k){
            ans += dp[n][j][tk];
        }
    }
    cout << fixed << setprecision(12) << ans << endl;
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