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

const int N = 75 + 1, M = 20, mod = 1e9 + 7;

int n;
string s;
int dp[N][1 << M];

int caldp(int i, int msk){
    if (i == n + 1){
        if (msk && (1 << __builtin_popcount(msk)) == msk + 1){
            return 1;
        }
        else{
            return 0;
        }
    }
    if (dp[i][msk] != -1){
        return dp[i][msk];
    }
    dp[i][msk] = 0;
    if (s[i] == '0'){
        return dp[i][msk] = caldp(i + 1, msk);
    }
    int x = 0, idx = i;
    while (idx <= n){
        x *= 2; x += s[idx] - '0';
        if (x > M){
            break;
        }
        dp[i][msk] += caldp(idx + 1, msk | (1 << (x - 1)));
        if (dp[i][msk] >= mod) dp[i][msk] -= mod;
        idx++;
    }
    if (msk && (1 << __builtin_popcount(msk)) == msk + 1){
        dp[i][msk]++;
        if (dp[i][msk] >= mod) dp[i][msk] -= mod;
    }
    return dp[i][msk];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    cin >> s; s = ' ' + s;
    int ans = 0;
    ForE(i, 1, n){
        ans += caldp(i, 0);
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