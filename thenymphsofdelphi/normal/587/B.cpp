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

int n; ll l; int k;
vi a;
vpii b;
vvi dp;
int ans;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> l >> k;
    a.assign(n, 0); b.assign(n, make_pair(0, 0)); dp.assign(k + 1, vi(n, 0));
    For(i, 0, n){
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(bend(b));
    ForE(j, 1, k){
        int tans = 0, idx = -1;
        For(i, 0, n){
            if (j == 1){
                dp[j][b[i].se] = 1;
                continue;
            }
            while (idx + 1 < n and b[idx + 1].fi <= b[i].fi){
                idx++;
                tans += dp[j - 1][b[idx].se];
                if (tans >= mod) tans -= mod;
            }
            dp[j][b[i].se] = tans;
        }
    }
    ForE(j, 1, k){
        if (l / n < j){
            continue;
        }
        int tans = 0;
        For(i, 0, n){
            tans += dp[j][i];
            if (tans >= mod) tans -= mod;
        }
        tans = (l / n - j + 1) % mod * tans % mod;
        ans += tans;
        if (ans >= mod) ans -= mod;
    }
    if (l % n){
        ForE(j, 1, k){
            if (l / n + 1 < j){
                continue;
            }
            int tans = 0;
            For(i, 0, l % n){
                tans += dp[j][i];
                if (tans >= mod) tans -= mod;
            }
            ans += tans;
            if (ans >= mod) ans -= mod;
        }
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