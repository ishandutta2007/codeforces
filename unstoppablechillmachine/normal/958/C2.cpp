#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
//using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
//#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)
#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-9;

int dp[20010][51][101], mod, arr[20010];

_ int sum(int a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
    return a;
}

_ void source() {
    int n, k;
    cin >> n >> k >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] %= mod;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int cur_sum = 0; cur_sum < mod; cur_sum++) {
                dp[i][j][cur_sum] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int cur_sum = 0; cur_sum < mod; cur_sum++) {
                if (j) dp[i + 1][j][sum(cur_sum, arr[i + 1])] = max(dp[i + 1][j][sum(cur_sum, arr[i + 1])], dp[i][j][cur_sum] - cur_sum + sum(cur_sum, arr[i + 1]));
                if (j < k) {
                    dp[i + 1][j + 1][arr[i + 1]] = max(dp[i + 1][j + 1][arr[i + 1]], dp[i][j][cur_sum] + arr[i + 1]);
                }
            }
        }
    }
    int ans = 0;
    for (int cur_sum = 0; cur_sum < mod; cur_sum++) {
        ans = max(ans, dp[n][k][cur_sum]);
        //cout << dp[n][k][cur_sum] << endl;
    }
    cout << ans;
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}