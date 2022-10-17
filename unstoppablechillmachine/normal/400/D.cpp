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

const int N = 1e5 + 10;
const int K = 510;

int arr[K][K], p[N], sz[N];

_ void init(int v) {
    p[v] = v;
    sz[v] = 1;
}

_ int find(int v) {
    return (p[v] == v ? v : p[v] = find(p[v]));
}

_ void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
        return;
    }
    if (sz[a] < sz[b]) {
        swap(a, b);
    }
    p[b] = a;
    sz[a] += sz[b];
}

_ void source() {
    int n, m, k;
    cin >> n >> m >> k;
    int sum = 0;
    vector<int> pref;
    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        sum += x;
        pref.pb(sum);
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (i != j) {
                arr[i][j] = INF;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        init(i);
    }
    for (int i = 1; i <= m; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        if (!cost) {
            merge(u, v);
        }
        int a = lower_bound(all(pref), u) - pref.begin() + 1, b = lower_bound(all(pref), v) - pref.begin() + 1;
        arr[a][b] = min(arr[a][b], cost);
        arr[b][a] = min(arr[b][a], cost);
    }
    bool t = true;
    for (int i = 1; i <= n; i++) {
        if (find(all(pref), i) != pref.end()) {
            continue;
        }
        if (find(i) != find(i + 1)) {
            t = false;
            break;
        }
    }
    if (!t) {
        cout << "No";
        exit(0);
    }
    cout << "Yes" << endl;
    for (int kk = 1; kk <= k; kk++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                arr[i][j] = min(arr[i][j], arr[i][kk] + arr[kk][j]);
            }
        }
    }
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            cout << (arr[i][j] == INF ? -1 : arr[i][j]) << ' ';
        }
        cout << endl;
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