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

const int N = 50 + 5, infll = (ld)1e18 + 7;

bool cmp1(const pii& lhs, const pii& rhs){
    if (lhs.fi != rhs.fi){
        return lhs.fi > rhs.fi;
    }
    return lhs.se > rhs.se;
}

int n;
pii a[N];

int b[N];
vpii ranges = {{0, 0}};
int dp[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi;
        a[i].fi *= 1000;
    }
    ForE(i, 1, n){
        cin >> a[i].se;
    }

    sort(a + 1, a + 1 + n, cmp1);
    int idx = 1;
    ForE(i, 2, n){
        if (a[i].fi != a[i - 1].fi){
            ranges.emplace_back(idx, i - 1);
            idx = i;
        }
    }
    ranges.emplace_back(idx, n);

    int lo = 1, hi = 1e14;
    while (lo < hi){
        int mid = (lo + hi) / 2;
        ForE(i, 1, n){
            a[i].se *= mid;
        }
        ForE(i, 1, n){
            b[i] = b[i - 1] + a[i].fi - a[i].se;
        }
        memset(dp, 0, sizeof(dp));
        For(i, 0, isz(ranges)){
            ForE(j, 0, n){
                dp[i][j] = infll;
            }
        }
        dp[0][0] = 0;
        For(i, 1, isz(ranges)){
            int l = ranges[i].fi, r = ranges[i].se, len = r - l + 1;
            ForE(j, 0, n - len){
                ForE(k, 0, min(len, j)){
                    dp[i][j + len - k - k] = min(dp[i][j + len - k - k], dp[i - 1][j] + b[l + len - k - 1] - b[l - 1]);
                }
            }
        }
        int ans = infll;
        ForE(j, 0, n){
            ans = min(ans, dp[isz(ranges) - 1][j]);
        }
        if (ans <= 0){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
        ForE(i, 1, n){
            a[i].se /= mid;
        }
    }
    cout << lo << endl;
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