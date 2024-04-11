#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
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
//#define endl "\n"

#define right rightt
#define left leftt
#define next nextt
#define prev prevv

mt19937 Random(int(time(0)));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;
const ld EPS = 1e-6;

int t1[110], t2[110], dp[110][500010], mod, arr[500010];
_ void upd1(int v, int val) {
    for (; v <= mod; v += v & (-v)) {
        t1[v] = min(t1[v], val);
    }
}

_ void upd2(int v, int val) {
    for (; v <= mod; v += v & (-v)) {
        t2[v] = min(t2[v], val);
    }
}

_ int get_min1(int v) {
    int res = INF;
    for (; v > 0; v -= v & (-v)) {
        res = min(res, t1[v]);
    }
    return res;
}

_ int get_min2(int v) {
    int res = INF;
    for (; v > 0; v -= v & (-v)) {
        res = min(res, t2[v]);
    }
    return res;
}

_ void source() {
    int n, k;
    cin >> n >> k >> mod;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        arr[i] = (arr[i - 1] + a) % mod;
    }
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= mod; j++) {
            t1[j] = INF;
            t2[j] = INF;
        }
        upd1(1, dp[i - 1][0] + mod);
        upd2(mod, dp[i - 1][0] + mod);
        for (int j = 1; j <= n; j++) {
            dp[i][j] = min(get_min1(arr[j] + 1) - mod + arr[j], get_min2(mod - arr[j] - 1) + arr[j]);
            upd1(arr[j] + 1, dp[i - 1][j] + mod - arr[j]);
            upd2(mod - arr[j], dp[i - 1][j] + mod - arr[j]);
        }
    }
    cout << dp[k][n];
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