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

const int N = 1e6 + 5, mod = 1e9 + 7;

int n;
int a[N];

int dp[N][2];
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
        a[i]--;
    }
    ForE(i, 1, n){
        vi b;
        b.push_back(a[i - 1]);
        b.push_back(a[i]);
        b.push_back(a[i + 1]);
        b.push_back(0);
        sort(bend(b)); reverse(bend(b));
        For(j, 0, isz(b)){
            if (b[j] == 0){
                break;
            }
            if (b[j] == b[j + 1]){
                continue;
            }
            if (b[j] > a[i]){
                continue;
            }
            if (b[j + 1] >= a[i + 1]){
                dp[i][0] += b[j] - b[j + 1];
                if (dp[i][0] >= mod) dp[i][0] -= mod;
                if (b[j + 1] < a[i - 1]){
                    dp[i][0] += (ll)dp[i - 1][1] * (b[j] - b[j + 1]) % mod;
                    if (dp[i][0] >= mod) dp[i][0] -= mod;
                }
            }
            else{
                dp[i][1] += b[j] - b[j + 1];
                if (dp[i][1] >= mod) dp[i][1] -= mod;
                if (b[j + 1] < a[i - 1]){
                    dp[i][1] += (ll)dp[i - 1][1] * (b[j] - b[j + 1]) % mod;
                    if (dp[i][1] >= mod) dp[i][1] -= mod;
                }
            }
        }
    }
    ForE(i, 1, n){
        ans += dp[i][0];
        if (ans >= mod) ans -= mod;
        ans += dp[i][1];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << endl;
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