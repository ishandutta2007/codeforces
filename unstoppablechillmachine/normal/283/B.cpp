#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

const int N = 2e5 + 10;
bool was[N][2];
int used[N][2], arr[N], n;
ll dp[N][2];

_ void go(int cur, int step) {
    used[cur][step] = 1;
    int to = (step ? cur - arr[cur] : cur + arr[cur]);
    if (to > n || to <= 0) {
        used[cur][step] = 2;
        dp[cur][step] = arr[cur];
        return;
    }
    if (used[to][step ^ 1] == 1) {
        dp[cur][step] = -1;
    }
    else {
        if (!used[to][step ^ 1]) {
            go(to, step ^ 1);
        }
        if (dp[to][step ^ 1] == -1) {
            dp[cur][step] = -1;
        }
        else {
            dp[cur][step] = dp[to][step ^ 1] + arr[cur];
            was[cur][step] |= was[to][step ^ 1];
        }
    }
    used[cur][step] = 2;
    return;
}

_ void source() {
    cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> arr[i];
    }
    dp[1][1] = 0;
    dp[1][0] = -1;
    used[1][0] = 1;
    used[1][1] = 2;
    was[1][1] = true;
    for (int i = 2; i <= n; i++) {
        if (!used[i][0]) {
            go(i, 0);
        }
        if (!used[i][1]) {
            go(i, 1);
        }
    }
    for (int i = 1; i < n; i++) {
        cout << (dp[i + 1][1] == -1 ? -1 : i + dp[i + 1][1] + was[i + 1][1] * i) << '\n';
    }
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