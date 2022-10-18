#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")

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

const int N = 1e3 + 5, M = 1e5 + 5, mod = 998244353;

int n, k, mx;
int a[N];

int b[M], ans;
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    sort(a + 1, a + 1 + n);
    dp[0][0] = 1;
    ForE(val, 1, mx){
        if (val * (k - 1) > mx){
            break;
        }
        ForE(i, 1, n){
            dp[1][i] = 1;
        }
        ForE(j, 2, k){
            int idx = 0, sum = 0;
            ForE(i, 1, n){
                while (idx < n and a[idx + 1] <= a[i] - val){
                    idx++;
                    sum += dp[j - 1][idx];
                    if (sum >= mod) sum -= mod;
                }
                dp[j][i] = sum;
            }
        }
        ForE(i, 1, n){
            b[val] += dp[k][i];
            if (b[val] >= mod) b[val] -= mod;
        }
    }
    FordE(val, M - 1, 1){
        ans += (ll)val * (b[val] - b[val + 1] + mod) % mod;
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/