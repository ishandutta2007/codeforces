#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long

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

const int N = 1e5 + 5, M = 1e2 + 5, mod = 998244353;

int n, k, l;
int a[N];

map <int, int> mpp;
int type[N];
int dp[N][M];
int sum[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    cin >> n >> k >> l;
    ForE(i, 1, n){
        cin >> a[i];
    }
    if (l == 1){
        cout << 0 << endl;
        return 0;
    }
    For(i, 1, l){
        if (a[i] != -1){
            mpp[a[i]]++;
        }
    }
    ForE(i, l, n){
        if (a[i] != -1){
            mpp[a[i]]++;
        }
        if (mpp.size() == 0){
            type[i] = 0;
        }
        else if (mpp.size() == 1){
            type[i] = mpp.begin()->fi;
        }
        else{
            type[i] = -1;
        }
        if (a[i - l + 1] != -1){
            mpp[a[i - l + 1]]--;
            if (mpp[a[i - l + 1]] == 0){
                mpp.erase(a[i - l + 1]);
            }
        }
    }
    ForE(i, 1, n){
        if (i < l){
            if (a[i] == -1){
                ForE(j, 1, k){
                    dp[i][j] = (i == 1 ? 1 : sum[i - 1]);
                    sum[i] += dp[i][j]; if (sum[i] >= mod) sum[i] -= mod;
                }
            }
            else{
                dp[i][a[i]] = (i == 1 ? 1 : sum[i - 1]);
                sum[i] = dp[i][a[i]];
            }
            continue;
        }
        ForE(j, 1, k){
            if (a[i] == -1 or a[i] == j){
                dp[i][j] = sum[i - 1];
                if (type[i] == 0 or type[i] == j){
                    if (i == l){
                        dp[i][j]--; if (dp[i][j] < 0) dp[i][j] += mod;
                        sum[i] += dp[i][j]; if (sum[i] >= mod) sum[i] -= mod;
                        continue;
                    }
                    dp[i][j] -= (sum[i - l] - dp[i - l][j]) % mod; if (dp[i][j] >= mod) dp[i][j] -= mod; if (dp[i][j] < 0) dp[i][j] += mod;
                }
                sum[i] += dp[i][j]; if (sum[i] >= mod) sum[i] -= mod;
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    cout << sum[n] << endl; 
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