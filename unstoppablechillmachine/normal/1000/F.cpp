//I_l_M_P
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
#pragma GCC optimize ("Ofast,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")

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

const int N = 5e5 + 10;
int arr[N], next[N];
vector<int> pos(N, INF);
pair<int, int> t[4 * N];

_ void build(int v, int l, int r) {
    if (l == r) {
        if (pos[arr[l]] == l) {
            t[v] = {next[l], l};
        }
        else {
            t[v] = {0, l};
        }
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

_ void upd(int v, int l, int r, int need) {
    if (l == r) {
        t[v].f = next[l];
        return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
        upd(2 * v, l, mid, need);
    }
    else {
        upd(2 * v + 1, mid + 1, r, need);
    }
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

_ pair<int, int> get_max(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return {-INF, -INF};
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

_ void source() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = n; i >= 1; i--) {
        next[i] = pos[arr[i]];
        pos[arr[i]] = i;
    }
    build(1, 1, n);
    int m;
    cin >> m;
    vector<pair<pair<int, int>, int> > query(m);
    for (int i = 0; i < m; i++) {
        cin >> query[i].f.f >> query[i].f.sec;
        query[i].sec = i;
    }
    sort(all(query));
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        if (i) {
            for (int j = query[i - 1].f.f; j < query[i].f.f; j++) {
                if (next[j] < INF) {
                    upd(1, 1, n, next[j]);
                }
            }
        }
        pair<int, int> kek = get_max(1, 1, n, query[i].f.f, query[i].f.sec);
        if (kek.f > query[i].f.sec) {
            ans[query[i].sec] = arr[kek.sec];
        }
    }
    for (auto it : ans) {
        cout << it << '\n';
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