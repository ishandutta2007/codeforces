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

vector<ld> arr;
int n;

pair<ld, int> check(ld penalty) {
    vector<pair<ld, int> > dp(n);
    for (int i = 2; i < n; i++) {
        dp[i] = {BINF, BINF};
    }
    dp[1] = min(mk(ld(0), ll(0)), mk(ld(arr[1] - arr[0] - penalty), ll(1)));
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1], {dp[i - 2].f + (arr[i] - arr[i - 1] - penalty), dp[i - 2].sec + 1});
    }
    return dp[n - 1];
}

_ void source() {
    int k;
    cin >> k >> n;
    arr.rsz(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (i & 1) arr[i] += EPS;
        else arr[i] -= EPS;
    }
    sort(all(arr));
    ld l = 0, r = 1e12 + 10;
    for (int it = 0; it < 100; it++) {
        ld mid = (l + r) / 2.0;
        if (check(mid).sec >= k) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    pair<ld, int> kek = check(r);
    //assert(kek.sec == k);
    cout << ll(round(kek.f + (ld)k * r));
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