#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

//const int MAX_MEM = 1e8; int mpos = 0; char mem[MAX_MEM]; inline void * operator new ( size_t n ) { char *res = mem + mpos; mpos += n; assert(mpos <= MAX_MEM); return (void *)res; } inline void operator delete ( void * ) { }

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
#define int ll
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

const int N = 1e6 + 10;
bool blocked[N];
int cost[N], cnt[N], left[N];

_ void source() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        x++;
        blocked[x] = true;
    }
    for (int i = 1; i <= k; i++) {
        cin >> cost[i];
    }
    if (blocked[1]) {
        cout << -1;
        exit(0);
    }
    left[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (blocked[i]) {
            left[i] = left[i - 1];
        }
        else {
            left[i] = i;
        }
    }
    int ans = BINF;
    for (int i = k; i >= 1; i--) {
        if (cnt[i]) {
            ans = min(ans, cnt[i] * cost[i]);
            continue;
        }
        int cur = 1, max_step = 0;
        bool t = true;
        while (cur + i <= n) {
            cnt[i]++;
            if (left[cur + i] <= cur) {
                t = false;
                break;
            }
            max_step = max(max_step, left[cur + i] - cur);
            cur = left[cur + i];
        }
        cnt[i]++;
        max_step = max(max_step, n - cur + 1);
        if (!t) {
            cnt[i] = 2e12;
        }
        ans = min(ans, cost[i] * cnt[i]);
        for (int j = i - 1; j >= max_step; j--) {
            cnt[j] = cnt[i];
        }
    }
    cout << (ans > 1e12 ? -1 : ans);
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