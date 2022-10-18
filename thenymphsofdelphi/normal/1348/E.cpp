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

const int N = 5e2 + 5;

int n, k;
int a[N], b[N];

int c[N];
bool dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> k;
    ForE(i, 1, n){
        cin >> a[i] >> b[i];
    }
    ForE(i, 1, n){
        c[i] = (c[i - 1] + a[i] + b[i]) % k;
    }
    dp[0][0] = 1;
    ForE(i, 1, n){
        For(ja, 0, k){
            int jb = c[i] - ja;
            if (jb < 0) jb += k;
            For(tja, 0, k){
                int tjb = c[i - 1] - tja;
                if (tjb < 0) tjb += k;
                int da = ja - tja;
                if (da < 0) da += k;
                int db = jb - tjb;
                if (db < 0) db += k;
                if (da <= a[i] and db <= b[i]){
                    dp[i][ja] |= dp[i - 1][tja];
                }
            }
        }
    }
    ll sum = 0, ans = 0;
    ForE(i, 1, n){
        sum += a[i] + b[i];
    }
    For(ja, 0, k){
        int jb = c[n] - ja;
        if (jb < 0) jb += k;
        if (dp[n][ja]){
            ans = max(ans, (sum - ja - jb) / k);
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