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

const int N = 1e4 + 10;
bitset<N> can[4 * N];
vector<int> have[4 * N];

void upd(int v, int l, int r, int a, int b, int x) {
    if (l > b || r < a) {
        return;
    }
    if (l >= a && r <= b) {
        have[v].pb(x);
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * v, l, mid, a, b, x);
    upd(2 * v + 1, mid + 1, r, a, b, x);
}

void go(int v, int l, int r) {
    if (l == r) {
        can[v].set(0);
        for (auto it : have[v]) {
            can[v] |= can[v] << it;
        }
        return;
    }
    int mid = (l + r) / 2;
    go(2 * v, l, mid);
    go(2 * v + 1, mid + 1, r);
    can[v] = can[2 * v] | can[2 * v + 1];
    for (auto it : have[v]) {
        can[v] |= can[v] << it;
    }
}

_ void source() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        upd(1, 1, n, l, r, x);
    }
    go(1, 1, n);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (can[1].test(i)) {
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 1; i <= n; i++) {
        if (can[1].test(i)) {
            cout << i << ' ';
        }
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