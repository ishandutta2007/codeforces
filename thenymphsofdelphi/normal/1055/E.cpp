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

#define left __left__

const int N = 1e3 + 5e2 + 5;

int n, s, m, k;
int a[N];
pii segments[N];

int left[N];
bool b[N]; int c[N];
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> s >> m >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
    ForE(i, 1, s){
        cin >> segments[i].fi >> segments[i].se;
    }
    ForE(i, 1, n){
        left[i] = n + 1;
    }
    ForE(i, 1, s){
        ForE(j, segments[i].fi, segments[i].se){
            left[j] = min(left[j], segments[i].fi);
        }
    }
    int lo = 1, hi = 1e9 + 1;
    while (lo < hi){
        int mid = (lo + hi) >> 1;
        ForE(i, 1, n){
            b[i] = (a[i] <= mid);
            c[i] = c[i - 1] + b[i];
        }
        ForE(i, 1, n){
            ForE(j, 1, m){
                dp[i][j] = dp[i - 1][j];
                if (left[i] <= i){
                    dp[i][j] = max(dp[i][j], dp[left[i] - 1][j - 1] + c[i] - c[left[i] - 1]);
                }
            }
        }
        if (dp[n][m] >= k){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    if (lo == 1e9 + 1){
        cout << -1 << endl;
    }
    else{
        cout << lo << endl;
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